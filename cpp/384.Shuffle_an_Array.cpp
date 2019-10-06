class Solution {
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        // vector<int> v1 = nums, v2;
        // while(v1.size()) {
        //     int ran = rand() % v1.size();
        //     v2.push_back(v1[ran]);
        //     v1.erase(v1.begin() + ran);
        // }    
        // return v2;

        vector<int> result = nums;
        for(int i = 0; i < result.size(); i++){
            int pos = rand() % result.size() - i;
            swap(result[i], result[pos + i]);
        }
        return result;
    }

private:
    vector<int> nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */