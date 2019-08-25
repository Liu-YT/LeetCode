class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int size = primes.size(), i = 0;
        vector<int> index(size, 0);
        vector<int> nums(n);
        nums[0] = 1;

        while(++i < n) {
            int minN = nums[index[0]] * primes[0];
            for(int j = 1; j < size; ++j) {
                if(minN > nums[index[j]] * primes[j]) {
                    minN = nums[index[j]] * primes[j];
                }
            }

            for(int j = 0; j < size; ++j) {
                if(minN == nums[index[j]] * primes[j]) {
                    index[j] += 1;
                }
            }

            nums[i] = minN;
        }

        // for(int j = 0; j < n; ++j) {
        //     cout << nums[j] << " ";
        // }

        return nums[n-1];
    }
};