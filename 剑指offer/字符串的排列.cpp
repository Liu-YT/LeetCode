class Solution {
public:
    vector<string> Permutation(string str) {
        if(str == "") {
            return {};
        }
        int size = str.size();
        vector<bool> used(size, false);
        vector<string> v;
        helper(str, "", v, used);
        return v;
    }

    void helper(string str, string cur, vector<string> &v, vector<bool> &used) {
        if(cur.size() == str.size()) {
            for(auto s : v) {
                if(cur == s) {
                    return;
                }
            }
            v.push_back(cur);
            return;
        }

        for(int i = 0; i < str.size(); i++) {
            if(!used[i]) {
                used[i] = true;
                helper(str, cur+str[i], v, used);
                used[i] = false;
            }
        }
    }
};