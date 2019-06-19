// 二进制高精度加法

class Solution {
public:
    string addBinary(string a, string b) {
        string ans = ""; // 答案字符串
        int carry = 0; // 进位
        int i, j;
        for(i = a.length() - 1, j = b.length() - 1; i >= 0 && j >= 0; --i, --j) {
    		ans += (a[i] - '0' + b[j] - '0' + carry) % 2 + '0';
        	carry = a[i] - '0' + b[j] - '0' + carry >= 2 ? 1 : 0;
        }

        if(a.length() >= b.length()) {
        	for(; i >= 0; --i) {
        		ans += (a[i] - '0' + carry) % 2 + '0';
        		carry = a[i] - '0' + carry >= 2 ? 1 : 0;
        	}
        }
        else {
        	for(; j >= 0; --j) {
        		ans += (b[j] - '0' + carry) % 2 + '0';
        		carry = b[j] - '0' + carry >= 2 ? 1 : 0;
        	}
        }

        if(carry)
        	ans += carry + '0';

        reverse(ans.begin(), ans.end()); 
        return ans;
    }
};