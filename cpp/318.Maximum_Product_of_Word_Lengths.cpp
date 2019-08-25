// solution 1 暴力破解
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int size = words.size();
        int ans = 0;
        for(int i = 0; i < size - 1; ++i) {
            set<char> s;
            for(auto c : words[i])  
                s.insert(c);
            for(int j = i + 1; j < size; ++j) {
                bool flag = true;
                for(auto c : words[j]) {
                    if(s.count(c)) {
                        flag = false;
                        break;
                    }
                }

                if(!flag)   continue;
                // cout << words[i].length() << words[j].size();
                ans = max(ans, (int)(words[i].length() * words[j].length()));
            }
        }
        return ans;
    }
};

// solution 2
// 用后26位来对应26个字母，若为1，说明该对应位置的字母出现过，那么每个单词的都可由一个int数字表示，两个单词没有共同字母的条件是这两个int数想与为0
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int size = words.size();
        int ans = 0;
        
        vector<int> mask(size, 0);
        for(int i = 0; i < size; ++i) {
            for(auto c : words[i])
            mask[i] |= 1 << (c - 'a');
        }

        for(int i = 0; i < size - 1; ++i) {
            for(int j = i + 1; j < size; ++j) {
                if((mask[i] & mask[j]) == 0) {
                    ans = max(ans, (int)(words[i].length() * words[j].length()));
                }
            }
        }

        return ans;
    }
};