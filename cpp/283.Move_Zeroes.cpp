class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i = 0, j = 0; i < nums.size(); i++) {
            if(nums[i] != 0)    nums[j++] = nums[i];
            if(i == nums.size()-1) {
                while(j < nums.size())    nums[j++] = 0;
            }
        }
    }
};