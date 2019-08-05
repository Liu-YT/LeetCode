class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;

        int m = matrix.size(), n = matrix[0].size();
        int dp[m][n], maxLen = 0;

        for(int i = 0; i < m; i++) {
            dp[i][0] = matrix[i][0] == '1' ? 1 : 0;
            maxLen = max(maxLen, dp[i][0]);        
        }
        for(int i = 0; i < n; i++) {
            dp[0][i] = matrix[0][i] == '1' ? 1 : 0;
            maxLen = max(maxLen, dp[0][i]);
        }        
    
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = 0;
                if(matrix[i][j] == '0') continue;
                dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                maxLen = max(maxLen, dp[i][j]);
            }
        }
        return maxLen * maxLen;
    }
};