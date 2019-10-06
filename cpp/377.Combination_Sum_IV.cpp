class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<long> dp(target+1, 0);

        dp[0] = 1;

        for(int i = 0; i <= target; i++) {
            for(int j = 0; j < nums.size(); j++) {
                if(i >= nums[j]) {
                    dp[i] = (dp[i] + dp[i - nums[j]]) % INT_MAX;
                }
            }
        }

        return dp[target];
    }
};