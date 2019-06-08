class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	string str = "";
    	if(strs.size() == 0)	return str;
    	str = strs[0];
    	if(strs.size() == 1)	return str;
    	for(int i = 1; i < strs.size(); ++i) {
    		string temp = "";
    		for(int j = 0; j < str.size() && j < strs[i].size(); ++j)
    			if(str[j] == strs[i][j])
    				temp += str[j];
    			else
    				break;
    		str = temp;
    	}
    	return str;
    }
};