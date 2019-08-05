// https://leetcode.com/problems/shortest-palindrome/solution/

/* solution 1 */
class Solution {
public:
    string shortestPalindrome(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        for(int i = 0; i < s.size(); i++) {
            if(s.substr(0, s.size()-i) == r.substr(i))
                return r.substr(0, i) + s;
        }
        return "";
    }
};

/* solution 2 */
class Solution {
public:
    string shortestPalindrome(string s) {
        int i = 0;
        for(int j = s.size()-1; j >= 0; j--) {
            if(s[j] == s[i])    i++;
        }
        if(i == s.size())   return s;
        string r = s.substr(i);
        reverse(r.begin(), r.end());
        return r + shortestPalindrome(s.substr(0, i)) + s.substr(i);
    }
};

/* solution 3 */
class Solution {
public:
    string shortestPalindrome(string s) {
        
    }
};