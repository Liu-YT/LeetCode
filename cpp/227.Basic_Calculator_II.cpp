/* solution 1 */
class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        char op = '+';
        int num;
        for(int i = 0; i < s.size(); i++) {
            // digit
            if(s[i] >= '0' && s[i] <= '9') {
                num = s[i] - '0';
                while(i + 1 < s.size() && s[i+1] >= '0' && s[i+1] <= '9') {
                    num = num * 10 + (s[++i] - '0');
                }
            }

            if(i == s.size()-1 || ((s[i] < '0' || s[i] > '9') && s[i] != ' ')) {
                // +, -, *, /
                if(op == '+') {
                    nums.push(num);
                }
                else if(op == '-') {
                    nums.push(-1 * num);
                }
                else if(op == '*') {
                    int top = nums.top();
                    nums.pop();
                    nums.push(top * num);
                }
                else {
                    int top = nums.top();
                    nums.pop();
                    nums.push(top / num);
                }
                op = s[i];
            }

            // space
            if (s[i] == ' ')
                continue;
        }

        int ans = 0;
        while(!nums.empty()) {
            ans += nums.top();
            nums.pop();
        }

        return ans;
    }
};

/* solution 2 */
class Solution {
public:
    int calculate(string s) {
        int i = 0, ans = 0, num = 0;
        int interim = 0;
        char op = '+';
        while(i < s.size()){
            if(isdigit(s[i])){
                num = 0;
                while(i < s.size() && isdigit(s[i])){
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                if(op == '+' || op == '-'){
                    ans += interim;
                    interim = num * (op == '-' ? -1 : 1);
                }else if(op == '*'){
                    interim *= num;
                }else if(op == '/'){
                    interim /= num;
                }
                continue;
            }
            
            if(s[i] != ' ') op = s[i];
           
            i++;
        }    

        ans += interim;            
        return ans;
    }
};