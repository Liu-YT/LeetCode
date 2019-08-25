// 超时
class Solution {
public:
    int numSquares(int n) {
        vector<bool> nums(n+1, false);
        for(int i = 1; i <= n; i++) {
            if(i * i <= n)  nums[i*i] = true; 
            else break;
        }

        vector<int> dp(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            if(nums[i]) {
                dp[i] = 1;
                continue;
            }

            dp[i] = i;
            for(int j = 1; j < i; j++) {
                if(nums[j])
                    dp[i] = min(dp[j] + dp[i-j], dp[i]);
            }
        }

        return dp[n];

    }
};

// solution 1
class Solution {
public:
    int numSquares(int n) {
        vector<bool> nums(n+1, false);
        for(int i = 1; i <= n; i++) {
            if(i * i <= n)  nums[i*i] = true; 
            else break;
        }

        vector<int> dp(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            if(nums[i]) {
                dp[i] = 1;
                continue;
            }

            dp[i] = i;
            for(int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i-j*j]+1, dp[i]);
            }
        }

        return dp[n];

    }
};

