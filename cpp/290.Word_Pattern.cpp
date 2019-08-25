class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, string> m1;
        map<string, char> m2;
        
        vector<string> v;
        string cur = "";
        for(int i = 0; i < str.size(); i++) {
            if(str[i] == ' ') {
                v.push_back(cur);
                cur = "";
                continue;
            }
            cur += str[i];
        }
        v.push_back(cur);

        if(v.size() != pattern.size())  return false;

        for(int i = 0; i < pattern.size(); i++) {
            if(m1.count(pattern[i]) && m2.count(v[i]) && m1[pattern[i]] == v[i] && m2[v[i]] == pattern[i])  continue;
            if(m1.count(pattern[i]) == 0 && m2.count(v[i]) == 0) {
                m1[pattern[i]] = v[i];
                m2[v[i]] = pattern[i];            
            }
            else {
                return false;
            }
        }
        
        return true;
    } 
};