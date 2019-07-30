class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> m;
        vector<string> v;
        for(int i = 0; i <= int(s.size() - 10); i++) {
            m[s.substr(i, 10)]++;
        }
        for(auto item : m) {
            if(item.second > 1) {
                v.push_back(item.first);
            }
        }
        return v;
    }
};