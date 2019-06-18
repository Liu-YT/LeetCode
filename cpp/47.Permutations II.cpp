// 数组排序后再进行全排列，需要注意的是存在重复的数字，需要在第一层循环的地方判断跳过一些与前面同一层一样的情况

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
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
    		if(i > 0 && !isVis[i-1] && nums[i] == nums[i-1])	continue;
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