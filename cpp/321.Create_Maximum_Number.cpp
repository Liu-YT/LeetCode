class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans(k, 0);
        int size1 = nums1.size(), size2 = nums2.size();
        for(int i = 0; i <= k; i++) {
            if(size1 < i || size2 < (k - i))    continue;      
            ans = max(ans, merge(maxVec(nums1, i), maxVec(nums2, k-i)));
        }
        return ans;
    }

    vector<int> maxVec(vector<int> num, int k) {
        int drop = num.size() - k;
        vector<int> v;
        for(int i = 0; i < num.size(); ++i) {
            while(drop > 0 && !v.empty() && v.back() < num[i]) {
                drop--;
                v.pop_back();
            }
            v.push_back(num[i]);
        }
        v.resize(k);

        return v;
    }

    vector<int> merge(vector<int> a, vector<int> b) {
        vector<int> res;
        while (!a.empty() || !b.empty()) {
            vector<int> &v = (a > b) ? a : b;
            res.push_back(v[0]);
            v.erase(v.begin());
        }
        return res;
    }
};