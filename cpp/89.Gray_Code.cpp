class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        // n == 0
        result.push_back(0);
        
        // n > 0
        for(int i = 0; i < n; ++i) {
            for(int j = result.size()-1; j >= 0; j--) {
                result.push_back((1 << i) + result[j]);
            }
        }
        return result;
    }
};


class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        for(int i = 0; i < (1<<n); ++i) {
            result.push_back(i^i>>1);
        }
        return result;
    }
};