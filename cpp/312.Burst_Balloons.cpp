// time limit
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int ans = 0;
        int size = nums.size();
        vector<bool> used(size, false);
        for(int i = 0; i < size; i++) {
            used[i] = true;
            ans = max(ans, helper(nums, used, i));
            used[i] = false;
        }

        return ans;
    }

    int helper(vector<int>& nums, vector<bool> &used, int index) {
        int size = nums.size();
        int left = 1, right = 1;
        
        for(int i = index + 1; i < size; i++) {
            if(!used[i]) {
                right = nums[i];
                break;
            }
        }

        for(int i = index - 1; i >= 0; i--) {
            if(!used[i]) {
                left = nums[i];
                break;
            }
        }
        
        int base = left * right * nums[index], ans = base;

        for(int i = 0; i < size; i++) {
            if(!used[i]) {
                used[i] = true;
                ans = max(ans, helper(nums, used, i) + base);
                used[i] = false;
            }
        }

        return ans;
    }
};


// time limit
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int ans = 0;
        int size = nums.size();
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        vector<vector<int> > dp(size+2, vector<int> (size+2, 0));

        for(int len = 1; len <= size; len++) {
            for(int start = 1; start + len - 1 <= size; start++) {
                int end = start + len - 1;
                for(int k = start; k <= end; k++) {
                    dp[start][end] = max(dp[start][end], dp[start][k-1] + dp[k+1][end] + nums[k] * nums[start-1] * nums[end+1]);
                }
            }
        }

        return dp[1][size];
    }
};