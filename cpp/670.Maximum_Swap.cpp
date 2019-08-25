class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        unordered_map<int, int> m;
        for(int i = 0; i < s.size(); i++) {
            m[s[i]-'0'] = i;
        }
        for(int i = 0; i < s.size(); i++) {
            for(int j = 9; j > (s[i] - '0'); j--) {
                if(m.count(j) && m[j] > i) {
                    s[m[j]] = s[i]; 
                    s[i] = j + '0';
                    return stoi(s);
                }
            }
        }
        return num;
    }
};