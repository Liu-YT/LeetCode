class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) {
            return 1;
        }

        if(n == 1) {
            return 10;
        }

        int size = min(n + 1, 12);
        vector<int> cnt(size, 0);
        cnt[0] = 0;
        cnt[1] = 10;

        for(int i = 2; i < size; i++) {
            int cur = 9, bit = 9;
            for(int j = 1; j < i; j++) {
                cur *= bit;
                bit--;
            }
            cnt[i] = cur + cnt[i-1];
        }
        return cnt[size-1];
    }
};