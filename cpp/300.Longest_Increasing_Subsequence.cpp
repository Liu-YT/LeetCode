class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v(nums.size(), 1);
        int ans = 0;

        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    v[i] = max(v[i], v[j] + 1);
                }
            }
            ans = max(ans, v[i]);
        }
        return ans;
    }
};