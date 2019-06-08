class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;  // 记录最长字串的长度
        int tmp = 0;        // 遍历字符串时候记录当前字串的长度
        int array[128];
        memset(array, -1, sizeof(int) * 128);
        for(int i = 0; i < s.length(); ++i) {
            if(array[s[i]] == -1) 
                ++tmp;
            else {
                for(int j = 0;j < 128; ++j)
                    if(array[j] < array[s[i]])
                        array[j] = -1;
                tmp = i - array[s[i]];
            }
            maxLength = maxLength > tmp ? maxLength : tmp;
            array[s[i]] = i;
        }
        return maxLength;
    }
};