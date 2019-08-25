class NumArray {
public:
    NumArray(vector<int>& nums) {
        int pre = 0;
        for(auto val : nums) {
            this->nums.push_back(pre);
            pre += val;
        }
        this->nums.push_back(pre);
    }
    
    int sumRange(int i, int j) {
        // cout << nums.size() << endl;
        return nums[j+1] - nums[i];
    }
private:
    vector<int> nums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */