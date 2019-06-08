// stack

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> myStack;
        myStack.push(-1);
        int num = 0;
        for(int i = 0; i < s.size(); ++i) {
        	if(s[i] == '(')
        		myStack.push(i);
        	else {
    			myStack.pop();
    			if(myStack.empty()) 
    				myStack.push(i);
    			else {
    				num = max(num, i - myStack.top());
    			}
        	}
        }
        return num;
    }
};


// dp

class Solution {
public:
    int longestValidParentheses(string s) {
    	if(!s.size())	return 0;
    	int maxNum = 0;
    	int num[s.size()] = {0};
    	for(int i = 1; i < s.size(); ++i){
    		if(s[i] == ')' && s[i-1] == '(') {
    			// "...()..."
				num[i] = (i >= 2 ? num[i-2] : 0) + 2;
    		}
    		else if(s[i] == ')' && s[i-1] == ')' && i >= num[i-1] + 1 && s[i-num[i-1]-1] == '(') {
				// "...((...))..." 
    			num[i] = num[i-1] + 2 + (i >= num[i-1] + 2 ? num[i - num[i-1] - 2] : 0);

    		}
    		maxNum = max(maxNum, num[i]);
    	}
    	return maxNum;
    }
};