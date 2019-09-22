class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<int> total(sum, 0);
        for(int i = 1; i < sum; i++) {
            total[i] = total[i-1] + i;
        }

        vector<vector<int>> ans;
        for(int i = 1; i < sum; i++) {
            for(int j = 0; j < i; j++) {
                if(total[i] - total[j] == sum) {
                    vector<int> cur;
                    for(int k = j + 1; k <= i; k++) {
                        cur.push_back(k);
                    }
                    ans.push_back(cur);
                }
            }
        }

        return ans;
    }
};