class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> m;
        for(auto c : s) {
            m[c]++;
        }  
        for(auto c : t) {
            m[c]--;
            if(m[c] < 0)
                return c;
        }
        return ' ';
    }
};


class Solution {
public:
    char findTheDifference(string s, string t) {
        int result = 0;
        for(auto c : s) {
            result = result ^ c;
        }
        for(auto c : t) {
            result = result ^ c;
        } 
        return (char)result;
    }
};