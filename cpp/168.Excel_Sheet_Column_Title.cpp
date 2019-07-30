class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        while(n) {
            n -= 1;
            ans += (n % 26) + 'A';
            n /= 26; 
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};