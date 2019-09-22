class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        vector<int> nums;
        int num = 1;
        nums.push_back(num);
        int cnt = 1, i = 0, j = 0, k = 0;
        
        while(cnt++ < index) {
            
            num = nums[i] * 2;
            num = min(num, min(nums[j] * 3, nums[k] * 5));
            
            nums.push_back(num);

            if(num == nums[i] * 2) {
                ++i;
            }

            if(num == nums[j] * 3) {
                ++j;
            }

            if(num == nums[k] * 5) {
                ++k;
            }
        }

        return nums[index-1];
    }
};