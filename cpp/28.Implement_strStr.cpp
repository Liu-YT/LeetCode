class Solution {
public:
    int strStr(string haystack, string needle) {
    	if(needle == "")	return 0;
    	int index = -1;
    	for(int i = 0; i < haystack.size(); ++i) {
    		if(haystack[i] == needle[0]) {
    			int k = i, flag = 1;
    			for(int j = 0; j < needle.size(); ++j) {
    				if(haystack[k++] != needle[j]) {
    					flag = 0;
    					break;
    				}
    			}
    			if(flag) {
    				index = i;
    				break;
    			}
    		}
    	}

    	return index;    
    }
};