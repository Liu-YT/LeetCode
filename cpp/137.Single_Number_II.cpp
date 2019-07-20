/* solution 1 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> m;
        for(int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        for(auto it : m) {
            if(it.second == 1)
                return it.first;
        }
        return -1;
    }
};

/* solution 2 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num
    }
};
