class Solution {
public:
    int cutRope(int number) {
        if(number == 0 || number == 1) {
            return 0;
        }

        if(number == 2) {
            return 1;
        }

        vector<int> nums(number+1, 0);
        
        nums[1] = 1;
        nums[2] = 1;
        
        for(int i = 3; i <= number; i++) {
            for(int j = 1; j < i; j++) {
                nums[i] = max(nums[i], max(j * (i - j), nums[j] * (i-j)));
            }
        }

        return nums[number];
    }
};