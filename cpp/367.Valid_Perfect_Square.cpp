class Solution {
public:
    bool isPerfectSquare(int num) {
        long long i;
        for(i = 2; i * i <= num; i++);
        return (i-1) * (i -1) == num;
    }
};