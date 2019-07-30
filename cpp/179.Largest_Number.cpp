class Solution {
public:
    static bool cmp(string a, string b) {
        return a+b > b+a;
    }
    
    string largestNumber(vector<int>& nums) {
        vector<string> n;
        for(int i = 0; i < nums.size(); i++) {
            n.push_back(to_string(nums[i]));
        }

        sort(n.begin(), n.end(), cmp);

        string ans = "";
        for(int i = 0; i < n.size(); i++) {
            ans += n[i];
        }

        int index = 0;
        for(int i = 0; i < ans.size()-1; i++)
            if(ans[i] == '0') index++;
            else   break;
        
        return ans.substr(index);
    }
};