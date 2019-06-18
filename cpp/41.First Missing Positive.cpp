class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int minPos = 1;
        int size = nums.size(); 
        for(int i = 0; i < size; ) {
        	if(nums[i] < size && nums[i] >= 1 && nums[i] != nums[nums[i] - 1]) {
        		int tmp = nums[nums[i] - 1];
        		nums[nums[i] - 1] = nums[i];
        		nums[i] = tmp;
        	}
        	else {
        		++i;
        	}

        }

        for(int i = 0; i < size; ++i) 
        	if(i != nums[i] - 1)
        		return i + 1;
      
        return size + 1;
    }
};