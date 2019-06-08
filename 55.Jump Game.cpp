class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxDis = 0;
        for(int i = 0; i < nums.size(); ++i) {
        	if(maxDis < i)	return false;
        	else {
        		maxDis = max(nums[i] + i, maxDis);
        		if(maxDis >= nums.size()-1)	return true;
        	}
        }
    }
};


class Solution {
public:
	bool canJump(vector<int>& nums) {
		int maxDis = 0;
		int len = nums.size();
		int i = 0;
		while(maxDis < len - 1 && maxDis >= i && i < len) {
			maxDis = max(maxDis, i + nums[i]);
			++i;
		}
		return maxDis >= len - 1;
	}
};


