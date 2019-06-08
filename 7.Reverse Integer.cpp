class Solution {
public:
    int reverse(int x) {
        int ans = 0, flag = 1, preAns = 0;
        if(x < 0) flag = -1; 
        while(x) {
        	if(flag && (ans > INT_MAX / 10 || ans == INT_MAX / 10 && abs(x % 10) > INT_MAX % 10))	return 0;
        	if(!flag && (ans > INT_MAX / 10 || ans == INT_MAX / 10 && abs(x % 10) > INT_MAX % 10 + 1))	return 0;
        	ans = ans * 10 + abs(x % 10);
        	x = x / 10;
        }
        return ans * flag;
    }
};