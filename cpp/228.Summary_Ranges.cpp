class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;

        int start = 0, end = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(i+1 < nums.size() && nums[i] + 1 == nums[i+1]) {
                end++;
                continue;
            }
            
            string str = to_string(nums[start]);
            if(start < end) str += "->" + to_string(nums[end]);
            ans.push_back(str);
            start = end = i+1;
        }

        return ans;
    }
};