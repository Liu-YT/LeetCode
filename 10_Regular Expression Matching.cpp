class Solution {
public:
    bool isMatch(string s, string p) {
    	int m = s.length(), n = p.length();
    	bool dp[m+1][n+1];
    	for(int i = 0; i <= m; ++i)
    		for(int j = 0; j <= n; ++j)
    			dp[i][j] = false;

    	dp[0][0] = true;
    	
    	if(m >= 1 && n >= 1)
    		dp[1][1] = s[0] == p[0] || p[0] == '.';

    	for(int j = 2; j <= n; ++j)
    		dp[0][j] = dp[0][j-2] && p[j-1] == '*';

    	for(int i = 1; i <= m; ++i) {
    		for(int j = 2; j <= n; ++j) {
    			if(p[j-1] == '*') {
    				//当p[j-1]出现0次时，前i位和前j-2位是匹配的
                    //当p[j-1]出现1次或多次时，第i位一定匹配第j-1位，且前i-1位一定和前j位是匹配的。
    				dp[i][j] = dp[i][j-2] || dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.');
    			}
    			else {
    				// 前i-1位和前j-1位是匹配的，且第i位和第j位是匹配的
    				dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
    			}
    		}
    	}
    	return dp[m][n];
    }
};