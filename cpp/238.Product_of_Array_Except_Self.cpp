class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> left(size, 0), right(size, 0);
        left[0] = right[size-1] = 1;
        for(int i = 1; i < size; i++)
            left[i] = left[i-1] * nums[i-1];
        for(int i = size - 2; i >= 0; i--) 
            right[i] = right[i+1] * nums[i+1];
        vector<int> ans;
        for(int i = 0; i < size; i++)  
            ans.push_back(left[i]*right[i]);
        return ans;
    }
};