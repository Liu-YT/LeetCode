class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)    return 0;
        if(nums.size() == 1)    return nums[0];
        if(nums.size() == 2)    return max(nums[0], nums[1]);

        int size = nums.size();
        int a[size] = {0}, b[size] = {0};

        a[0] = nums[0];
        a[1] = nums[1];
        // end in n-1
        for(int i = 2; i < size-1; i++) {
            a[i] = nums[i] + max((i-2 >= 0 ? a[i-2] : 0), (i-3 >= 0 ? a[i-3] : 0));
        }
        
        b[1] = nums[1];
        b[2] = nums[2];
        // start in n
        for(int i = 3; i < size; i++) {
            b[i] = nums[i] + max((i-2 >= 1 ? b[i-2] : 0), (i-3 >= 1 ? b[i-3] : 0));
        }

        int ans = INT_MIN;
        for(int i = 0; i < size; i++) {        
            ans = max(ans, max(a[i], b[i]));
        }

        return ans;
    }
};