class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        priority_queue<pair<int, int>> q;
        
        for(auto num : nums) {
            m[num]++;
        }

        for(auto p : m) {
            q.push(make_pair(p.second, p.first));
        }

        vector<int> ans;
        for(int i = 0; i < k; i++) {
            auto top = q.top();
            q.pop();
            ans.push_back(top.second);
        }

        return ans;
    }
};