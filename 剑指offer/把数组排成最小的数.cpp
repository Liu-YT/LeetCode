class Solution {
public:

    static bool cmp(string a, string b) {
        if(a + b >= b + a) {
            return false;
        }
        return true;
    }

    string PrintMinNumber(vector<int> numbers) {
        string ans = "";
        vector<string> v;
        for(auto num : numbers) {
            v.push_back(to_string(num));
        }
        sort(v.begin(), v.end(), cmp);
        for(auto num : v) {
            ans += num;
        }
        return ans;
    }
};