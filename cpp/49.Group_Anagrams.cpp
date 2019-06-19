class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    	vector<vector<string>> res;
    	map<string, vector<string>> myMap;
    	for(auto &str : strs) {
    		string sstr = str;
    		sort(sstr.begin(), sstr.end());
    		myMap[sstr].push_back(str);
    	}

    	for(auto &v : myMap) {
    		res.push_back(v.second);
    	}

    	return res;
    }
};