class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0)    return 0;
        int size = nums.size();
        int cMax[size], cMin[size];
        cMax[0] = cMin[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            int a = cMax[i-1] * nums[i];
            int b = cMin[i-1] * nums[i];
            cMax[i] = max(a, max(b, nums[i]));
            cMin[i] = min(a, min(b, nums[i]));
        }

        int maxPro = INT_MIN;
        for(int i = 0; i < size; i++)
            maxPro = max(maxPro, cMax[i]);
        return maxPro;
    }
};