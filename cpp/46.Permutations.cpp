class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
    	vector<int> vec(nums.size());
    	sort(nums.begin(), nums.end());
    	bool isVis[nums.size()] = { false };
     	sol(res, nums, vec, isVis, 0);
    	return res;
    }

    void sol(vector<vector<int>>& res, vector<int>& nums, vector<int>& vec, bool *isVis, int step) {
    	if(step == nums.size()) {
    		res.push_back(vec);
    		return;
    	}
    	for(int i = 0; i < nums.size(); ++i) {
    		if(!isVis[i]) {
    			isVis[i] = true;
    			vec[step++] = nums[i];
    			sol(res, nums, vec, isVis, step);
    			--step;
    			isVis[i] = false;
    		}
            
    	}
    }
};