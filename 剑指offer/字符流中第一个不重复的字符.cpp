class Solution
{
public:

    //Insert one char from stringstream
    void Insert(char ch) {
        m[ch]++;
        str += ch;
    }
    
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        for(auto c : str) {
            if(m[c] == 1) {
                return c;
            }
        }
        return '#';
    }

    string str;
    map<char, int> m;
};