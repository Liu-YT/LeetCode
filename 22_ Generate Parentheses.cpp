class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> v;
		string str = "";
		dfs(str, 0, 0, n, v);
		return v;
	}

	void dfs(string buildStr, int left, int right, int n, vector<string> &v) {
		if(left + right == 2 * n) {
			v.push_back(string(buildStr));
			return;
		}

		if(left < n) {
			dfs(buildStr + "(", left + 1, right, n, v);
		}
		
		if(right < left) {
			dfs(buildStr + ")", left, right + 1, n, v);
		}
	}
};