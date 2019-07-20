class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)    return 0;
        int len = 1, maxLen = 1;
        set<int> s;
        for(int i = 0; i < nums.size(); ++i) 
            s.insert(nums[i]);
        for(auto iter = s.begin(); iter != s.end(); ) {
            int pre = *iter;
            while(++iter != s.end() && pre + 1 == (*iter))  {
                pre = *iter;
                len++;
            }
            if(len > maxLen) maxLen = len;
            len = 1;
        }
        return maxLen;
    }
};