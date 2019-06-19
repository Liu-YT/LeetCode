// https://leetcode.com/problems/next-permutation/solution/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    	for(int i = nums.size() - 1; i >= 1; --i) {
			if(nums[i] > nums[i-1]) {
				int j = i, minJ = j;
				while(j < nums.size() && nums[j] > nums[i-1]) {
					if(nums[j] - nums[i-1] <= nums[minJ] - nums[i-1])
						minJ = j;
					++j;
				}
				j = minJ;
				int temp = nums[j];
				nums[j] = nums[i-1];
				nums[i-1] = temp;
				reverse(nums.begin() + i, nums.end());
				return;
			}
		}
		reverse(nums.begin(), nums.end());
    }
};