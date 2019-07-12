/* solution 1 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> res;
        for(int i = 1; i <= rowIndex+1; ++i) {
            vector<int> v;
            for(int j = 0; j < i; ++j) {
                if(j == 0 || j == i-1) {
                    v.push_back(1);
                } else {
                    v.push_back(res[i-2][j-1]+res[i-2][j]);
                }
            }
            res.push_back(v);
        }
        return res[rowIndex];
    }
};


/* solution 2 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v(rowIndex+1, 1);
        if(rowIndex < 2)   return v;
        int pre;
        for(int i = 2; i <= rowIndex; ++i) {
            pre = v[0];
            for(int j = 1; j <= i-1; ++j) {
                v[j] = v[j] + pre;
                pre = v[j] - pre;
            }
        }
        return v;
    }
};

/* solution 3 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v(rowIndex+1, 1);
        if(rowIndex < 2)   return v;
        for(int i = 2; i <= rowIndex; ++i) {
            for(int j = i-1; j >= 1; --j) {
                v[j] += v[j-1];
            }
        }
        return v;
    }
};