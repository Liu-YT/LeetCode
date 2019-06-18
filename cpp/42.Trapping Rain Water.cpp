// learn from https://leetcode.com/problems/trapping-rain-water/discuss/304524/O(n)-time-O(1)-space-solution

class Solution {
public:
    int trap(vector<int>& height) {
    	if(height.size() <= 2)	return 0;
    	int leftMax[height.size()], rightMax[height.size()];

    	// 计算每个位置的左边最大
    	leftMax[0] = height[0];
    	for(int i = 1; i < height.size(); ++i)	leftMax[i] = max(leftMax[i-1], height[i]);

    	// 计算每个位置的右边最大
    	rightMax[height.size() - 1] = height[height.size() - 1];
    	for(int i = height.size() - 2; i >= 0; --i) rightMax[i] = max(rightMax[i+1], height[i]);

    	// 计算结果
    	int count = 0;
    	for(int i = 1; i < height.size() - 1; ++i)
    		count += min(leftMax[i], rightMax[i]) - height[i];
    	
    	return count;
    }
};

