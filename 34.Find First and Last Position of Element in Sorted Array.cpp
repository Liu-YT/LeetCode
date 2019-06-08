class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid, i = -1, j = -1;
        while(left <= right) {
        	mid = (left + right) / 2;
        	if(nums[mid] == target) {
        		i = j = mid;
        		while(i > 0 && nums[i-1] == target) --i;
        		while(j < nums.size() - 1 && nums[j+1] == target)	++j;
        		break;
        	}
        	if(nums[mid] > target)	right = mid - 1;
        	else left = mid + 1;
        }

        return {i, j};
    }
};