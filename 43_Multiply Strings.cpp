class Solution {
public:
    string multiply(string num1, string num2) {
    	int a[num1.length()+1];
    	int b[num2.length()+1];
    	int ans[num1.length() + num2.length() + 1] = {0};
    	// 数字反转
    	for(int i = 1; i <= num1.length(); ++i)	a[i] = num1[num1.length() - i] - '0';
    	for(int i = 1; i <= num2.length(); ++i)	b[i] = num2[num2.length() - i] - '0';

    	// 模拟乘法
    	/*
			进位 cin =  (c[i+j-1] + a[i] * b[j]) / 10 
    		数字 c[i+j-1] = (c[i+j-1] + a[i] * b[j]) % 10 
    	*/
    	for(int i = 1; i <= num1.length(); ++i) {
    		for(int j = 1; j <= num2.length(); ++j) {
    			ans[i+j-1] = a[i] * b[j] + ans[i+j-1];
    			ans[i+j] = ans[i+j-1] / 10 + ans[i+j];
    			ans[i+j-1] = ans[i+j-1] % 10; 
    		}
    	}

        string str = "";
        bool flag = false;
        for(int i = num1.length() + num2.length(); i >= 1; --i) {
        	if(!flag && ans[i] == 0)
        		continue;
        	else {
        		flag = true;
        		str += ans[i] + '0';
        	}
        }
        return (str == "") ? "0" : str;
    }
};