class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int, int> myMap;
        for(int i = 0; i < nums.size(); ++i) {
            if(myMap.count(target - nums[i])) {
                ans.push_back(myMap.find(target - nums[i])->second);
                ans.push_back(i);
                return ans;
            } 
            else
            	myMap.insert(make_pair(nums[i], i));
        }
    }
};
