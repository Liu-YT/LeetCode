class Solution {
public:
    int modFac = 1337;
    /*
        a^(x+y) = a^x * a^y
        a^(x*y) = (a^x)^y
        (ab)%k = ((a%k)(b%k))%k 
     */
    int pMod(int a, int b) {
        if(b == 0) {
            return 1;
        }

        a = a % modFac;
        int res = a;
        for(int i = 1; i < b; i++) {
            res = res * a % modFac;
        }
        return res;
    }

    int superPow(int a, vector<int>& b) {
        if(a == 0) {
            return 0;
        }

        if(b.size() == 0) {
            return 1;
        }

        int res = pMod(a, b[0]);
        for(int i = 1; i < b.size(); i++) {
            res = (pMod(res, 10) * pMod(a, b[i])) % modFac;
        }
        return res;
    }
};