// https://leetcode.com/articles/number-of-digit-one/
class Solution {
public:
    int countDigitOne(int n) {
        int cnt = 0;
        for(long long i = 1; i <= n; i *= 10) {
            long long div = i * 10;
            cnt += (n / div) * i + min(i, max(0LL, n % div - i + 1));
        }
        return cnt;
    }
};