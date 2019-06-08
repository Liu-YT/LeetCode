class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
    	// 【0, rightSide)
        long long rightSide = 1;
        int addNums = 0;
        for(auto num : nums) {
        	if(rightSide > n)	return addNums;
        	while (num > rightSide && rightSide <= n) {
        		rightSide += rightSide;
        		addNums++;
        	}
    		rightSide += num;		
        }
        while (rightSide <= n) {
        	rightSide += rightSide;
        	addNums++;
        }
        return addNums;
    }
};

class Solution {
	public:
		int minPatches(vector<int>& nums, int n) {
		// 【0, rightSide)
		long long rightSide = 1;
		int addNums = 0;
		int i = 0;
		int size = nums.size();

		while (rightSide <= n) {
			if(i < size && rightSide >= nums[i]) {
				rightSide = rightSide + nums[i];
				++i;
			} else {
				rightSide = rightSide + rightSide;
				++addNums; 
			}
		}
		return addNums;
	}
};