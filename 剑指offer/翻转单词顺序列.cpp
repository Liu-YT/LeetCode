class Solution {
public:
    string ReverseSentence(string str) {
        reverse(str, 0, str.size()-1);

        int l = 0;
        for(int i = 0; i < str.size(); i++) {
            if(str[i] == ' ') {
                reverse(str, l, i-1);
                l = i+1;
            }
        }

        reverse(str, l, str.size()-1);

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