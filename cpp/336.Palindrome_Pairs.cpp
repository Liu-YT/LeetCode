// Time Limit Exceeded
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        for(int i = 0; i < words.size(); ++i) {
            for(int j = 0; j < words.size(); ++j) {
                if(i == j) continue;
                if(isPar(words[i], words[j])) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }

    bool isPar(string a, string b) {
        string s1 = a + b, s2 = a + b;
        reverse(s2.begin(), s2.end());
        return s1 == s2;
    }
};


class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        unordered_map<string, int> dict;

        for(int i = 0; i < words.size(); i++)
            dict[words[i]] = i;
        
        for(int i = 0; i < words.size(); ++i) {
            dict.erase(words[i]);
            for(int j = 0; j <= words[i].size(); ++j) {
                string left = words[i].substr(0, j);
                string right = words[i].substr(j);
                string rLeft = left;
                reverse(rLeft.begin(), rLeft.end());
                string rRight = right;
                reverse(rRight.begin(), rRight.end());
                if(isPalindrome(left) && dict.count(rRight)) {
                    ans.push_back({dict[rRight], i});
                }

                if(j != words[i].size() && isPalindrome(right) && dict.count(rLeft)) {
                    ans.push_back({i, dict[rLeft]});
                }

            }
            dict[words[i]] = i;
        }
        

        return ans;
    }

    bool isPalindrome(string s) {
        int left = 0, right = s.size()-1;
        while(left < right) {
            if(s[left] != s[right]) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};
