class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;

        sort(nums.begin(), nums.end());

        for(int i = 0; i <= nums.size(); ++i) {
            sol(result, nums, temp, 0, i);
        }

        return result;
    }

    void sol(vector<vector<int>> &result, vector<int>& nums, vector<int> cur, int start, int size) {
        if(cur.size() == size) {
            result.push_back(cur);
            return;
        }

        for(int i = start; i < nums.size(); ++i) {
            if(i >= start + 1 && nums[i] == nums[i-1])  continue;
            cur.push_back(nums[i]);
            sol(result, nums, cur, i+1, size);
            cur.pop_back();
        }
    }
};