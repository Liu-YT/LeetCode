class NumArray {
public:
    NumArray(vector<int>& nums) {
        for(auto &num : nums) {
            this->nums.push_back(num);
        }
        sums.resize(nums.size()+1, 0);
        for(int i = 0; i < nums.size(); i++) {
            change(i+1, nums[i]);
        }
    }

    int lowbit(int x) {
        return x & (-x);
    }
    
    void change(int i, int val) {
        while(i < sums.size()) {
            sums[i] += val;
            i += lowbit(i);
        }
    }

    int sum(int n) {
        int ans = 0;
        while(n > 0) {
            ans += sums[n];
            n -= lowbit(n);
        }
        return ans;
    }

    void update(int i, int val) {
        int del = val - nums[i];
        nums[i] = val;
        change(i+1, del);
    }
    
    int sumRange(int i, int j) {
        return sum(j+1) - sum(i);
    }



private:
    vector<int> sums;
    vector<int> nums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */