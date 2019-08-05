/* solution 1 */
// 递归实现，将括号的运算递归获取，然后做计算，此处主要使用引用，执行完相关部分后将继续接着括号后的继续
class Solution {
public:
    int calculate(string s) {
        int start = 0;
        return helper("(" + s + ")", start);
    }

    int helper(string s, int &i) {
        int ans = 0, sign = 1, num = 0;
        while(++i < s.size()) {
            if(s[i] == ')') {
                return ans;
            }
            
            if(s[i] == ' ') continue;
            
            if(s[i] == '+') {
                sign = 1;
                continue;
            }
            
            if(s[i] == '-') {
                sign = -1;
                continue;
            }
            
            if(s[i] >= '0' && s[i] <= '9') {
                num = s[i] - '0';
                while(i + 1 < s.size() && s[i+1] >= '0' && s[i+1] <= '9') {
                    num = num * 10 + (s[i+1] - '0');
                    ++i;
                }
            }
            else if(s[i] == '(') {
                num = helper(s, i);
            }

            ans += sign * num;
        }
        return ans;
    }
};

/* solution 2 */
class Solution {
public:
    int calculate(string s) {
        stack<int> nums, op;
        int sign = 1, ans = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') continue;
            
             if(s[i] == '+') {
                sign = 1;
                continue;
            }
            
            if(s[i] == '-') {
                sign = -1;
                continue;
            }

            if(s[i] >= '0' && s[i] <= '9') {
                int num = s[i] - '0';
                while(i + 1 < s.size() && s[i+1] >= '0' && s[i+1] <= '9') {
                    num = num * 10 + (s[i+1] - '0');
                    ++i;
                }
                ans += num * sign;
            }

            if(s[i] == '(') {
                nums.push(ans);
                op.push(sign);
                ans = 0;
                sign = 1;
            }

            if(s[i] == ')') {
                ans *= op.top();
                op.pop();
                ans += nums.top();
                nums.pop();
            }
        }
        return ans;
    }
};