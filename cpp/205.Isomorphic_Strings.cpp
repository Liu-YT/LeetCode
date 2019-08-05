class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())    return false;
        unordered_map<char, int> sMap, tMap;
        for(int i = 0; i < s.size(); i++) {
            if(sMap.count(s[i]) ^ tMap.count(t[i]) || sMap[s[i]] != tMap[t[i]])
                return false;
            sMap[s[i]] = tMap[t[i]] = i;
        }
        return true;
    }
};