class Solution {
public:
    int Fibonacci(int n) {
        vector<int> nums(n+2, 0);
        nums[0] = 0;
        nums[1] = 1;
        for(int i = 2; i <= n; i++) {
            nums[i] = nums[i-1] + nums[i-2];
        }
        return nums[n];
    }
};

class Solution {
public:
    int Fibonacci(int n) {
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        int a = 0, b = 1;
        for(int i = 2; i <= n; i++) {
            b = a + b;
            a = b - a;
        }
        return b;
    }
};