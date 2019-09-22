// https://www.nowcoder.com/profile/3371548/codeBookDetail?submissionId=16319486
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        if(n <= 0) {
            return 0;
        }

        int cnt = 0;
        for(int i = 1; i <= n; i *= 10) {
            int div = i * 10;
            cnt += (n / div) * i + min(i, max(n % div - i + 1, 0));
        }
        return cnt;
    }
};