// 解法一 暴力破解


class Solution {
public:
    double myPow(double x, int n) {
        double result = 1.0;
        for(int i = 0; i < abs(n); ++i) {
        	result *= x;
        }
        return n > 0 ? result : 1 / result;
    }
};



// 解法二 分治 + 递归


class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0) {
        	// 越界判断--粗糙版
        	// x = 1.0 / x;
        	// if(n == INT_MIN)
        	// 	return x * myPow(x, -1* (n+1));
        	// else
        	// 	return myPow(x, -1 * n);
        	
        	// 越界判断--精简版 	
        	return 1.0 / (x * myPow(x, -1 * (n+1)));
        }
        else if(n == 0)
        	return 1.0;
        else {
        	double tmp = myPow(x, n / 2);
        	if(n % 2  == 0)
        		return tmp * tmp;
        	else 
        		return tmp * tmp * x;
        }
    }
};
