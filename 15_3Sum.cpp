class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		if(nums.size() < 3)	return {};
		vector<vector<int> > res;
		sort(nums.begin(), nums.end());
		for(int i = 0; i < nums.size() - 2; ++i) {
			if(nums[i] > 0) break;
			// 减少重复运算
			if(i > 0 && nums[i] == nums[i-1])	continue;
			int j = i + 1, k = nums.size() - 1;
			while(j < k) {
				if(nums[i] + nums[j] + nums[k] == 0) {
					res.push_back({nums[i], nums[j], nums[k]});
					// 避免重复
					while (j < k && nums[j] == nums[j + 1]) ++j;
                    while (j < k && nums[k] == nums[k - 1]) --k;
					++j;
					--k;
				}
				else if(nums[i] + nums[j] + nums[k] > 0) --k;
				else	++j;
			}
		}
		return res;	
    }
};
