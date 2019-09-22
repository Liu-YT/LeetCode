class Solution {
public:
    double Power(double base, int exponent) {
        if(exponent == 0)
            return 1;
        if(exponent == 1)
            return base;
        if(base == 0)
            return 0;
        if(exponent == -1)
            return 1 / base;

        double tmp = Power(base, exponent / 2);
        return tmp * tmp * Power(base, exponent % 2);
    }
};