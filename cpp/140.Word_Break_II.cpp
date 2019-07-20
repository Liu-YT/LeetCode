/* solution 超时 */
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res, cur;
        unordered_set<string> dict;
        for(auto word : wordDict) {
            dict.insert(word);
        }
        helper(s, dict, res, cur);
        return res;
    }

    void helper(string s, unordered_set<string> &dict, vector<string>& res, vector<string>& cur) {
        if(dict.count(s)) {
            string tmp = "";
            for(auto str : cur) {
                tmp += str + " ";
            }
            tmp += s;
            res.push_back(tmp);
        }
        for(int i = 0; i < s.size(); i++) {
            if(dict.count(s.substr(0, i+1))) {
                cur.push_back(s.substr(0, i+1));
                helper(s.substr(i + 1), dict, res, cur);
                cur.pop_back();
            }
        }
    }
};

/* solution 1 改进超时，记忆化搜索 */
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        unordered_map<string, vector<string>> m;
        for(auto word : wordDict) {
            dict.insert(word);
        }
        return helper(s, dict, m);
    }

    vector<string> helper(string s, unordered_set<string> &dict, unordered_map<string, vector<string>> &m) {
        if(m.count(s)) {
            return m[s];
        }
        vector<string> res;
        if(dict.count(s)) {
            res.push_back(s);
        }
        for(int i = 0; i < s.size(); i++) {
            if(dict.count(s.substr(0, i+1))) {
                vector<string> ans = helper(s.substr(i+1), dict, m);
                for(auto str : ans) {
                    res.push_back(s.substr(0, i+1) + " " + str);
                }
            }
        }
        m[s] = res;
        return res;
    }
};