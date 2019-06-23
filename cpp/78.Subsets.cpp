class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        for(int i = 0; i <= nums.size(); ++i)
            sol(result, nums, temp, i, 0);
        return result;
    }

    void sol(vector<vector<int>>& result, vector<int>& nums, vector<int>& cur, int size, int start) {
        if(cur.size() == size) {
            result.push_back(cur);
            return;
        }

        for(int i = start; i < nums.size(); ++i) {
            cur.push_back(nums[i]);
            sol(result, nums, cur, size, i+1);
            cur.pop_back();
        }
    }
};