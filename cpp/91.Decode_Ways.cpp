class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0 || s[0] == '0')    return 0;

        int cnt[s.size()+1] = {0};
        cnt[0] = cnt[1] = 1;

        for(int i = 2; i <= s.size(); ++i) {
            cnt[i] = (s[i-1] == '0') ? 0 : cnt[i-1];
            if(s[i-2] != '0' && (s[i-2]-'0') * 10 + s[i-1]-'0' <= 26 && (s[i-2]-'0') * 10 + s[i-1]-'0' > 0)
                cnt[i] += cnt[i-2];
        }

        return cnt[s.size()];
    }
};