class Solution {
/*
*	暴力搜索
*	检索所有可能性，使用map提高检索效率
*/

public:
    vector<int> findSubstring(string s, vector<string>& words) {
		if (s.empty() || words.empty() || s.size() < words.size() * words[0].size()) return {};
        vector<int> res;
        int n = words.size(), len = words[0].size();
        map<string, int> wordCnt;
        for(auto &word : words)	++wordCnt[word]; 
        for(int i = 0; i <= (s.size() - n * len); ++i) {
        	map<string, int> m;
        	int j = 0;
        	for(j = 0; j <= n; ++j) {
        		string str = s.substr(i + j * len, len);
        		if(!wordCnt.count(str)) break;
        		m[str]++;
        		if(m[str] > wordCnt[str])	break;
        	}
    		if(j == n)	res.push_back(i);
        }
        return res;
    }
};