// 记忆化搜索 + DP
class Solution {
public:
    int uniquePaths(int m, int n) {
    	vector<vector<int>> v;
    	for(int i = 0; i < m; ++i)	v.push_back(vector<int>(n, 0));
    	return solve(m, n, v);
    }

    int solve(int m, int n, vector<vector<int>>& v) {
    	if(m == 1 || n == 1)	return 1;
    	if(v[m-1][n-1] != 0)	return v[m-1][n-1];
    	v[m-1][n-1] = solve(m-1, n, v) + solve(m, n-1, v);
    	return v[m-1][n-1];
    }
};