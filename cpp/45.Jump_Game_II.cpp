class Solution {
public:
    int jump(vector<int>& nums) {
 		if(nums.size() == 0)	return 0;
        int maxDis = 0;
        int dp[nums.size()] = {0};
        for(int i = 0; i < nums.size(); ++i) {
        	if(i > maxDis)	return -1;
        	if(maxDis < i + nums[i]) {
        		maxDis = i + nums[i];
        		for(int j = i + 1; j <= maxDis && j < nums.size(); ++j) {
        			if(dp[j] == 0 || dp[j] > dp[i] + 1)	dp[j] = dp[i] + 1;
        		}
        	}
        }

        return dp[nums.size()-1];
    }
};