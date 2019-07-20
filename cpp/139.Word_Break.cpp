/* solution 超时 */
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(auto word : wordDict) {
            dict.insert(word);
        }
        return helper(s, dict);
    }

    bool helper(string s, unordered_set<string> &dict) {
        if(dict.count(s))   return true;
        for(int i = 0; i < s.size(); i++) {
            if(dict.count(s.substr(0, i+1)) && helper(s.substr(i+1), dict)) {
                return true;
            }
        }
        return false;
    }
};

/* solution 1 */
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(auto word : wordDict) {
            dict.insert(word);
        }
        bool dp[s.size()+1] = {false};
        dp[0] = true;
        for(int i = 1; i <= s.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(dict.count(s.substr(j, i-j)) && dp[j]) {
                    dp[i] = true;
                }
            }
        }
        return dp[s.size()];
    }
};

/* solution 2 */