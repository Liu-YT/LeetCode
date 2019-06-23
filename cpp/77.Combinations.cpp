// 解法 1
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if(n < k)   return {};
        vector<vector<int>> res;
        for(int i = 1; i <= n - k + 1; ++i) {
            auto temp = sol(i, n, k);
            if(!temp.empty()) {
                for(auto v : temp) {
                    res.push_back(v);
                }
            }
        }
        return res;   
    }

    vector<vector<int>> sol(int start, int n, int k) {
        vector<vector<int>> res;
        if(k == 1 && start <= n) return {{start}};
        for(int i = start + 1; i <= n; ++i) {
            if(k > 1 && n - i + 1 >= k - 1) {
                auto temp = sol(i, n, k-1);
                if(!temp.empty()) {
                    for(auto v : temp) {
                        v.push_back(start);
                        res.push_back(v);
                    }
                }
            }
        }
        return res;      
    }
};


// 解法 2
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if(n < k)   return {};
        vector<vector<int>> res;
        vector<int> temp;
        sol(1, n, k, temp, res);
        return res;   
    }

    void sol(int start, int n, int k, vector<int> &cur, vector<vector<int>> &res) {
        if(k == cur.size()) res.push_back(cur);
        else {
            for(int i = start; i <= n; ++i) {
                cur.push_back(i);
                sol(i+1, n, k, cur, res);
                cur.pop_back();
            }
        }
    }
};