class Solution {
public:
    int minCut(string s) {
  		if(s.size() <= 1)	return 0;

		// 判断区间[i, j]的字符是否是回文串
  		bool isPal[s.size()][s.size()];

  		// 记录区间[i, size]需要切割的次数
		int cut[s.size()+1];
        cut[s.size()] = -1;
		for(int i = s.size()-1; i >= 0; --i) {
			cut[i] = INT_MAX;
			for(int j = i; j < s.size(); ++j) {
				isPal[i][j] = false;
                if(i == j || i+1 == j && s[i] == s[j] || i+1 < j && isPal[i+1][j-1] && s[i] == s[j]) {
                    isPal[i][j] = true;
					cut[i] = min(cut[i], cut[j+1] + 1);
                }
			}
		}
		return cut[0];
    }
};