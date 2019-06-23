// hard
// https://leetcode.com/problems/minimum-window-substring/solution/

class Solution {
public:
    string minWindow(string s, string t) {
        if(s == "" || t == "")    return "";

        map<char, int> sMap, tMap;
        for(int i = 0; i < t.size(); ++i)   tMap[t[i]] += 1;
        
        int start = 0, end = s.size()-1, count = 0, minLen = INT_MAX, minStart = -1;

        for(int i = 0; i < s.size(); ++i) {
            sMap[s[i]]++;
            if(sMap[s[i]] <= tMap[s[i]])    ++count;
            if(count == t.size()) {
                while(start < i && sMap[s[start]] > tMap[s[start]]) {
                    sMap[s[start]]--;
                    start++;
                }

                if(i - start < minLen) {
                    minStart = start;
                    minLen = i - start + 1;
                    end = i;
                }

                // 跳过开头
                sMap[s[start]]--;
                start++;
                count--;
            }
        }
        
        return minStart == -1 ? "" : s.substr(minStart, minLen);
    }
};