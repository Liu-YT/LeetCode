/**
* 动态规划 如果从左上开始算 则遇到正值时就需要计算正值的盈余 因为需要累计往下计算
* 如果从右下开始往上算 遇到正的盈余就不用接着往下累计 直接更新成0就好
*/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(dungeon.size() == 0 || dungeon[0].size() == 0)   return 1;
        int m = dungeon.size(), n = dungeon[0].size();

        int dp[m][n];

        dp[m-1][n-1] = dungeon[m-1][n-1] >= 0 ? 0 : -dungeon[m-1][n-1];

        for(int i = m-2; i >= 0; i--) {
            dp[i][n-1] = max(0, dp[i+1][n-1] - dungeon[i][n-1]);
        } 

        for(int i = n-2; i >= 0; i--) {
            dp[m-1][i] = max(0, dp[m-1][i+1] - dungeon[m-1][i]);            
        }

        for(int i = m - 2; i >= 0; i--) {
            for(int j = n - 2; j >= 0; j--) {
                dp[i][j] = max(0, min(dp[i][j+1], dp[i+1][j]) - dungeon[i][j]);
            }
        }

        return dp[0][0] + 1;
    }
};