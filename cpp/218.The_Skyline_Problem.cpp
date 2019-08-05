class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        
        vector<pair<int, int>> height;
        for (auto &b : buildings) {
            height.push_back({b[0], -b[2]});
            height.push_back({b[1], b[2]});
        }
        sort(height.begin(), height.end());
        
        multiset<int> heap;
        heap.insert(0);
        vector<vector<int>> res;
        int pre = 0, cur = 0;
        for (auto &h : height) {
            if (h.second < 0) {
                heap.insert(-h.second);
            } else {
                heap.erase(heap.find(h.second));
            }   
            cur = *heap.rbegin();
            if (cur != pre) {
                res.push_back(vector<int>{h.first, cur});
                pre = cur;
            }
        }
        return res;
    }
};
