class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)    return 0;
        int dp[nums.size()] = {0}, maxM = -1;
        for(int i = 0; i < nums.size(); i++) {
            dp[i] = nums[i] + max(i-2>=0 ? dp[i-2] : 0, i-3>=0 ? dp[i-3] : 0);
            maxM = max(maxM, dp[i]);
        }
        return maxM;
    }
};