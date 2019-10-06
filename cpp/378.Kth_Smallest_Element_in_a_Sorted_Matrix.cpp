class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> nums;
        for(auto &item : matrix) {
            for(auto &num : item) {
                nums.push_back(num);
            }
        }
        sort(nums.begin(), nums.end());
        return nums[k-1];
    }
};

class Solution {
private:
    int upper_bound(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] <= target) l = mid + 1;
            else r = mid - 1;
        }
        return l;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        const size_t n = matrix.size();
        int l = matrix[0][0], r = matrix[n - 1][n - 1];
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                int upper = upper_bound(matrix[i], mid);
                cnt += upper;
            }
            if (cnt < k) l = mid + 1;
            else r = mid - 1;
        }
        return l;
    }
};