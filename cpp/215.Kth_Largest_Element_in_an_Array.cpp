class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return partiction(nums, k-1, 0, nums.size()-1);
    }

    int partiction(vector<int>& nums, int k, int start, int end) {
        int left = start, right = end;
        int cur = nums[start];
        while(left < right) {
            while(nums[right] <= cur && right > left) right--;
                nums[left] = nums[right];

            while(nums[left] >= cur && left < right) left++;
                nums[right] = nums[left];
        }
        // left == right
        nums[left] = cur;
        if(left - start == k) return cur;
        if(left - start > k) {
            return partiction(nums, k, start, left-1);
        }
        return partiction(nums, k-left+start-1, left+1, end);        
    }
};