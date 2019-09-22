class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int l = 0, r = data.size()-1;

        int cnt = 0;
        while(l <= r) {
            int m = (l + r) >> 1;
            if(data[m] == k) {
                cnt = 1;
                int tmp = m - 1;
                while(tmp >= 0 && data[tmp] == k) {
                    ++cnt;
                    --tmp;
                }
                tmp = m + 1;
                while(tmp < data.size() && data[tmp] == k) {
                    ++cnt;
                    ++tmp;
                }
                break;
            }
            else if(data[m] > k) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }

        return cnt;
    }
};