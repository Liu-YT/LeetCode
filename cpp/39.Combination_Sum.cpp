class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		if(candidates.size() == 0)	return {};
		sort(candidates.begin(), candidates.end());
		return sol(candidates, 0, target);   
    }

    vector<vector<int>> sol(vector<int>& candidates, int start, int target) {
    	vector<vector<int>> res;
    	for(int i = start; i < candidates.size(); ++i) {
    		if(candidates[i] == target) {
    			res.push_back({candidates[i]});
    			break;
    		}
    		else if(candidates[i] > target) break;
    		else {
    			vector<vector<int>> r = sol(candidates, i, target - candidates[i]);
    			for(auto &item : r) {
    				item.insert(item.begin(), candidates[i]);
    				res.push_back(item);
    			}
    		}
    	}
    	return res;
    }
};