class Solution {
public:
    int minDistance(string word1, string word2) {
		int m = word1.size();
		int n = word2.size();
		int dis[m+1][n+1] = {0};

		for (int i = 0; i <= m; ++i)
			dis[i][0] = i;

		for (int j = 0;j <= n; ++j)
			dis[0][j] = j;

		// m or n equal 0
		if (!m && !n)
			return max(m, n);

		// insert: 	dis[i, j] = dis[i][j-1] + 1	
		// delete:	dis[i, j] = dis[i-1][j] + 1
		// replace or no op：	dis[i, j] = dis[i-1][j-1] + (word1[i-1] == word2[j-1] ? 0 : 1)

		for (int i = 1; i <= m; ++i) {			
			for (int j = 1; j <= n; ++j) {
				dis[i][j] = min(dis[i][j-1] + 1,
					min(dis[i-1][j] + 1, dis[i-1][j-1] + (word1[i-1] == word2[j-1] ? 0 : 1)));
			}
		}
		return dis[m][n];
    }
};

