class Solution {
public:
    bool isNumeric(char* str) {
        // 标记符号、小数点、e是否出现过
        bool sign = false, decimal = false, hasE = false;

        for(int i = 0; i < strlen(str); i++) {
            if(str[i] == 'e' || str[i] == 'E') {
                if(i == strlen(str) - 1) {
                    // e 后面一定要接数字
                    return false;
                }

                // 两次 e
                if(hasE) {
                    return false;
                }

                hasE = true;
            }
            else if(str[i] == '+' || str[i] == '-') {
                // 第二次出现 +- 符号，必须紧接在 e 后面
                if(sign && str[i-1] != 'e' && str[i-1] != 'E') {
                    return false;
                }

                // 第一次出现 +- 符号，且不是在字符开头，则也需要紧接在 e 之后
                if(!sign && i > 0 && str[i-1] != 'e' && str[i-1] != 'E') {
                    return false;
                }

                sign = true;
            }
            else if(str[i] == '.') {
                // e 后面不能接小数点，小数点不难出现两次
                if(hasE || decimal) {
                    return false;
                }
                decimal = true;
            }
            else if(str[i] < '0' || str[i] > '9') {
                return false;
            }
        }

        return true;
    }
};