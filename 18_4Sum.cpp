class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    	if(nums.size() < 4)	return {};
    	sort(nums.begin(), nums.end());
    	vector<vector<int> > res;
    	for(int i = 0; i < nums.size() - 3; ++i) {
    		if(i > 0 && nums[i-1] == nums[i])	continue;
    		for(int j = i + 1; j < nums.size() - 2; ++j) {
    			if(nums[i] + nums[j] > target && target >= 0)	break;
    			if(j > i + 1 && nums[j] == nums[j - 1])	continue;
    			int k = j + 1, l = nums.size() - 1;
    			while(k < l) {
    				if(nums[i] + nums[j] + nums[k] + nums[l] == target) {
    					res.push_back({nums[i], nums[j], nums[k], nums[l]});
    					while(k < l && nums[k+1] == nums[k])	++k;
    					while(k < l && nums[l-1] == nums[l])	--l;
    					++k;
    					--l;
    				}
    				else if(nums[i] + nums[j] + nums[k] + nums[l] > target) --l;
    				else	++k;
    			}
    		}
    	}
    	return res;
    }
};