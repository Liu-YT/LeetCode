class Solution {
public:
    string getHint(string secret, string guess) {
        string ans = "";
        int cnt = 0;
        
        map<char, int> m;
        // cal bulls
        for(int i = 0; i < secret.size(); i++) {
            if(secret[i] == guess[i])   ++cnt;
            m[secret[i]]++;
            m[guess[i]]--;
        }
        ans += to_string(cnt) + "A";

        // cal cows
        int cur = 0;
        for(auto &iter : m) {
            cur += abs(iter.second);
        }
        ans += to_string((secret.size() * 2 - cur) / 2 - cnt) + "B";
        return ans;
    }
};