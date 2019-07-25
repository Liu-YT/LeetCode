class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res;
        if(denominator == 0)    return "";
        // 判断正负
        if(numerator < 0 && denominator > 0 || numerator >  0 && denominator < 0)
            res += "-";

        unordered_map<long, long> m;
        long n = abs((long)numerator);
        long d = abs((long)denominator);
        
        res += to_string(n / d);
        n = n % d;
        
        if(!n)  return res;

        res += ".";

        while(n) {
            if(m.count(n)) {
                res.insert(m[n % d], "(");
                res += ")";
                return res;
            }
            m[n] = res.size();
            res += n * 10 / d + '0';
            n = n * 10 % d;
        }
        return res;
    }
};