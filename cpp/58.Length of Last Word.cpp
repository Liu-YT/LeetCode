class Solution {
public:
    int lengthOfLastWord(string s) {
    	int num = 0;
    	bool flag = false;
    	for(int i = int(s.size() - 1); i >= 0; --i) {
    		if(s[i] == ' ') {
    			if(flag)	return num;
    			else	continue; 
    		}
    		flag = true;
    		++num;
    	}
    	return num;
    }
};