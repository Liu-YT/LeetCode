// time limit
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        int size = coins.size();
        int ans = INT_MAX, rest = amount;
        for(int i = size - 1; i >= 0; i--) {
            if(rest < coins[i]) continue;
            int tmp = coinChange(coins, rest - coins[i]);
            if(tmp == -1)   continue;
            ans = min(ans, 1 + tmp);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

// solution 1
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int size = coins.size();
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for(int i = 1; i <= amount; ++i) {
            for(int j = 0; j < size; ++j) {
                if(i < coins[j])    continue;
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }

        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};