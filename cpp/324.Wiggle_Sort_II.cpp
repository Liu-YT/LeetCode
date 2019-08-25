class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int size = nums.size();
        vector<int> tmp(nums);
        sort(tmp.begin(), tmp.end());

        int j = size, k = (size + 1) >> 1;
        for(int i = 0; i < size; ++i) {
            if((i & 1) == 1) {
                nums[i] = tmp[--j];
            }
            else {
                nums[i] = tmp[--k];
            }
        }
    }
};