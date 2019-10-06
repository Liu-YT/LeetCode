/* solution 1 */
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        
        for(int i = 0; i < min((int)nums1.size(), k); i++) {
            for(int j = 0; j < min((int)nums2.size(), k); j++) {
                ans.push_back({nums1[i], nums2[j]});
            }
        }

        sort(ans.begin(), ans.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] + a[1] < b[0] + b[1];
        });

        if(ans.size() > k) {
            ans.resize(k);
        }

        return ans;
    }
};

/* solution 2 */
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        multimap<int, vector<int>> m;
        for(int i = 0; i < min((int)nums1.size(), k); i++) {
            for(int j = 0; j < min((int)nums2.size(), k); j++) {
                m.insert({nums1[i] + nums2[j], {nums1[i], nums2[j]}});
            }
        }

        for(auto it = m.begin(); it != m.end(); ++it) {
            ans.push_back(it->second);
            if(--k <= 0) {
                break;
            }
        }

        return ans;
    }
};

/* solution 3 */
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        int size = min(k, (int)nums1.size() * (int)nums2.size());
        vector<int> index(nums1.size(), 0);
        for(int i = 0; i < size; i++) {
            int cur = 0, sum = INT_MAX;
            for(int j = 0; j < nums1.size(); j++) {
                if(index[j] < nums2.size() && sum >= nums1[j] + nums2[index[j]]) {
                    sum = nums1[j] + nums2[index[j]];
                    cur = j;
                }
            }
            ans.push_back({nums1[cur], nums2[index[cur]]});
            index[cur]++;
        }

        return ans;
    }
};