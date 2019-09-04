class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() > t.size())
            return false;
        int i = 0, j = 0;
        while(j < t.size()) {
            if(s[i] == t[j]) {
                ++i;
                ++j;
            }
            else {
                ++j;
            }
        }
        return i == s.size();
    }
};