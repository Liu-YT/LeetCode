class Solution {
public:
    int jumpFloorII(int number) {
        vector<int> dp(number+1, 0);
        int cur = 0;
        for(int i = 1; i <= number; i++) {
            dp[i] = cur + 1;
            cur += dp[i];
        }
        return dp[number];
    }
};