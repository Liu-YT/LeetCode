// 1
class Solution {
public:
    string countAndSay(int n) {
    	if(n == 1)	return "1";
    	else {
    		string res = countAndSay(n-1), s = "";
    		int count = 1, i = 0;
    		while(i < res.size()) {
    			if(i < res.size() - 1 && res[i] == res[i+1]) {
    				++i;
    				++count;
    			}
    			else {
    				s = s + char('0' + count) + res[i];
    				count = 1;
    				++i;
    			}
    		}
    		return s;
    	}
    }
};


// 2
class Solution {
public:
    string countAndSay(int n) {
    	if(n == 1)	return "1";
    	else {
    		string res = countAndSay(n-1), s = "";
    		int count = 1, i = 0;
    		while(i < res.size()) {
    			while(i < res.size() - 1 && res[i] == res[i+1]) {
    				++i;
    				++count;
    			}

				s = s + char('0' + count) + res[i];
				count = 1;
				++i;
    			
    		}
    		return s;
    	}
    }
};