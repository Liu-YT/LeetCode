class Solution {
public:
    int countPrimes(int n) {
        if(n < 2)   return 0;
        bool nums[n];
        for(int i = 2; i < n; i++) nums[i] = true;
        for(int i = 2; i < n; i++) {
            if(nums[i]) {
                for(int j = i + i; j < n; j += i)
                    nums[j] = false;
            }
        }

        int count = 0;
        for(int i = 2; i < n; i++) {
            if(nums[i]) ++count;
        }
        return count;
    }
};