class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(auto val : nums) {
            if(s.count(val))    return val;
            s.insert(val);
        }
        return -1;
    }
};

// https://leetcode.com/problems/find-the-duplicate-number/solution/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tortoise = nums[0];
        int hare = nums[0];
        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while(tortoise != hare);

        int p1 = nums[0];
        int p2 = tortoise;

        while (p1 != p2) {
            p1 = nums[p1];
            p2 = nums[p2];
        }

        return p1;
    }
};