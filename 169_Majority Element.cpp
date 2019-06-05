class Solution {
public:
    // moore majority vote algorithm
    int majorityElement(vector<int>& nums) {
        int m;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                m = nums[i];
                count++;
            } else if (nums[i] == m) {
                count++;
            } else
                count--;
        }
        return m;
    }
};