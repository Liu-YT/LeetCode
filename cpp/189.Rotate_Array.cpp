class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp;
        k = k % nums.size();
        for(int i = nums.size() - k; i < nums.size(); i++)
            temp.push_back(nums[i]);
        for(int i = nums.size()-1; i >= k; i--) {
            nums[i] = nums[i-k];
        }
        for(int i = 0; i < k; i++)
            nums[i] = temp[i];   
    }
};