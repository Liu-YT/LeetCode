class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())    return false;
        
        map<char, int> m1, m2;
        for(int i = 0; i < s.size(); i++)   m1[s[i]]++;
        for(int i = 0; i < t.size(); i++)   m2[t[i]]++;
        
        if(m1.size() != m2. size()) return false;
        for(auto it : m1) {
            if(m2.count(it.first) && it.second == m2[it.first])    continue;
            return false;
        }
        return true;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())    return false;
        
        map<char, int> m;
        for(int i = 0; i < s.size(); i++) {
            m[s[i]]++;
            m[t[i]]--;
        }
        
        for(auto it : m) {
            if(it.second != 0)    return false;
        }
        return true;
    }
};