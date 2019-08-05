class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> s;
        long long val;
        for(int i = 0; i < nums.size(); i++) {
            val = nums[i];
            if(i > k)   s.erase(nums[i-k-1]);
            auto pos = s.lower_bound(val - t);
            if(pos != s.end() && abs(*pos-val) <= t)  return true;
            s.insert(val);
        }
        return false;
    }
};