class Solution {
public:
    int divide(int dividend, int divisor) {
		if(divisor == -1 && dividend == INT_MIN)
			return INT_MAX;

		if(divisor == -1)
			return -dividend;

		if(divisor == 1)
			return dividend;

		int flag = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
		long a = labs(dividend);
		long b = labs(divisor);
    	return flag == -1 ? -myDivide(a, b) : myDivide(a, b);
    }

    long myDivide(long dividend, long divisor) {
    	if(dividend < divisor || dividend < 0)	return 0;
    	int sum = 1;
    	long temp = divisor;
    	while(dividend >= (temp + temp)) {
    		sum = sum << 1;
    		temp = temp << 1;
    	}
    	return sum + myDivide(dividend - temp, divisor);
    }
};