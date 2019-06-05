class Solution {
public:
    string convert(string s, int numRows) {
    	if(numRows == 1) return s;
    	string str = "";
    	for(int i = 0; i < numRows; ++i) {
    		if (i == 0) {
    			for(int j = 0; j < s.size(); ) {
    				str += s[j];
    				j += 2 * numRows - 2;
    			}			
    		}
    		else if(i == numRows - 1) {
    			for(int j = numRows-1; j < s.size(); ) {
    				str += s[j];
    				j += 2 * numRows - 2;
    			}
    		}
    		else {
    			int count = 0;
    			for(int j = i; j < s.size(); ) {
    				str += s[j];
    				if(count % 2 == 0)
    					j += 2 * (numRows - i) - 2;
    				else
    					j += 2 * i;
    				++count;
    			}
    		}
    	}
    	return str;
    }
};