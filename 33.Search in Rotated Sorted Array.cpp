class Solution {
public:
    int search(vector<int>& nums, int target) {
    	int left = 0, right = nums.size(), mid;
    	while(left <= right) {
    		mid = (left + right) / 2;
			if(nums[mid] == target)	return mid;
    		
    		if(nums[mid] < nums[right]) {
    			// [mid, right]有序
    			if(nums[mid] < target && nums[right] >= target)	left = mid + 1;
    			else right = mid - 1;
    		}
    		else {
    			// [left, i] [i+1, right]有序
    			if(nums[left] <= target && target < nums[mid])	right = mid - 1;
    			else	left = mid + 1;
    		}
    	}
    	return -1;
    }
};