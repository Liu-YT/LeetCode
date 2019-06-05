class Solution {
public:
	int myAtoi(string str) {
	    int ans = 0;		// 返回的数字
	    int sign = 1; 		// 返回数字的符号
	    int i = 0;
	    while(str[i] == ' ') { ++i; }
	    if(i < str.length && (str[i] == '+' || str[i] == '-')) {
	    	sign = str[i] == '+' ? 1 : -1;
	    	++i;
	    }
	    while(str[i] >= '0' && str[i] <= '9' && i < str.length()) {
	    	if(ans > INT_MAX / 10 || (ans == INT_MAX / 10  && str[i] > '7'))
	    		return sign == 1 ? INT_MAX : INT_MIN;
	    	ans = ans * 10 + str[i] - '0';
	    	++i;
	    }
		return ans * sign;
	}
};