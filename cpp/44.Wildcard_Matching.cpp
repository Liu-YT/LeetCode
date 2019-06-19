class Solution {
public:
    bool isMatch(string s, string p) {

    	if(s.size() == 0 && p.size() == 0)	return true;

    	int m = s.size(), n = p.size();
    	bool match[m+1][n+1];

    	for(int i = 0; i <= m; ++i)
    		for(int j = 0; j <= n; ++j)
    			match[i][j] = false;
    	
    	match[0][0] = true;

    	if(m >= 1 && n >= 1)
    		match[1][1] = (s[0] == p[0]) || (p[0] == '?') || (p[0] == '*');

    	for(int i = 1; i <= n; ++i)
    		match[0][i] = match[0][i-1] && (p[i-1] == '*');
    	for(int i = 1; i <= m; ++i) {
    		for(int j = 1; j <= n; ++j) {
    			if(p[j-1] == '*') 
    				match[i][j] = match[i][j-1] || match[i-1][j] || match[i-1][j-1];
				else
					match[i][j] = (match[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '?'));

    		}
    	}

    	return bool(match[m][n]);
    }
};