class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> m;
        while(!m.count(n) && n != 1) {
            int temp = 0, cur = n;
            while(n) {
                temp += (n % 10) * (n % 10);
                n = n / 10;
            }
            m[cur] = temp;
            n = temp;
        }
        if(n == 1) {
            return true;
        }
        return false;
    }
};