class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size() == 0) return 0;
        vector<int> nums(ratings.size(), 0);
        int total = 0;
        for(int i = 0; i < ratings.size(); ++i) {
            total += get(i, ratings, nums);
        }
        return total;
    }

    int get(int index, vector<int>& ratings, vector<int>& nums) {
        if(nums[index] != 0) return nums[index];

        nums[index] = 1;
        int a = INT_MIN, b = INT_MIN;
        if(index - 1 >= 0 && ratings[index-1] < ratings[index])
            a = get(index-1, ratings, nums);
        if(index + 1 < ratings.size() && ratings[index+1] < ratings[index])
            b = get(index+1, ratings, nums);

        int add = max(a, b);
        if(add > 0)
            nums[index] += add;
        return nums[index];
    }
};