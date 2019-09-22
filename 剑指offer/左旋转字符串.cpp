class Solution {
public:
    string LeftRotateString(string str, int n) {
        reverse(str, 0, str.size()-1);
        reverse(str, 0, str.size()-n-1);
        reverse(str, str.size()-n, str.size()-1);
        return str;
    }

    void reverse(string &str, int l, int r) {
        while(l < r) {
            char t = str[l];
            str[l] = str[r];
            str[r] = t;

            ++l;
            --r;
        }
    }
};