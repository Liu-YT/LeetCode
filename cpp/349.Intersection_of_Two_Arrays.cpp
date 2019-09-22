class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1, s2;
        vector<int> ans;
        for(auto num : nums1) {
            s1.insert(num);
        }
        for(auto num : nums2) {
            if(s1.count(num) && !s2.count(num)) {
                s2.insert(num);
                ans.push_back(num);
            }
        }

        return ans;
    }
};