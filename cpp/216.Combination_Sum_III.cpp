class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        bool used[10] = {false};
        return helper(k, n, 0, 1, used);
    }

    vector<vector<int>> helper(int k, int n, int cur, int start, bool *used) {
        vector<vector<int>> ans;
        if(k == 0) {
            if(cur == n) {
                vector<int> temp;
                for(int i = 1; i <= 9; i++)
                    if(used[i]) temp.push_back(i);
                ans.push_back(temp);
            }
            return ans;
        }

        for(int i = start; i <= 9; i++) {
            if(cur + i > n) break;
            used[i] = true;
            vector<vector<int>> a = helper(k-1, n, cur+i, i+1, used);
            for(auto v : a) {
                ans.push_back(v);
            }
            used[i] = false;
        }
        
        return ans;
    }
};