/* solution 1 */
// 暴力破解
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if(nums.size() == 0)    return ans;
        for(int i = 0; i <= nums.size() - k; i++) {
            int num = -1;
            for(int j = i; j < i + k; j++)
                num = max(nums[j], num);
            ans.push_back(num);
        }
        return ans;
    }
};

/* solution 2 */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if(nums.size() == 0)    return ans;
        deque<int> dq;
        for(int i = 0; i < nums.size(); i++) {
            while(!dq.empty() && nums[dq.front()] <= nums[i]) dq.pop_front();
            dq.push_front(i);
            if(dq.back() <= i - k)   dq.pop_back();
            if(i >= k-1) ans.push_back(nums[dq.back()]);
        }
        return ans;
    }
};
