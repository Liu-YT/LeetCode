class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num == 1)    return true;
        if(num <= 0 || num & 1 > 0)    return false;
        while(num >= 4 && num % 4 == 0) {
            num /= 4;
        }
        return num == 1;  
    }
};