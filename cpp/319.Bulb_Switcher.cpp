// time limit
class Solution {
public:
    int bulbSwitch(int n) {
        vector<bool> state(n, true);
        int ans = 0; 
        for(int i = 2; i <= n; i++) {
            for(int j = i - 1; j < n; j += i) {
                state[j] = !state[j];
            }
        }

        for(int i = 0; i < n; i++)
            ans += state[i];

        return ans;
    }
};

// solution 1

// For prime numbers, they must be off because we can reach them only twice (The first round and their own round).
/* For other numbers, if we can reach them odd times, then they are on; otherwise, they are off. So only 
 those numbers who have square root will be reached odd times and there are sqrt(n) of them because
 for every x > sqrt(n), x*x > n and thus should not be considered as the answer. */

class Solution {
public:
    int bulbSwitch(int n) {
       return sqrt(n);
    }
};