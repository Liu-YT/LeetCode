class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> ans;
        int l = 0, r = array.size()-1;
        while(l < r) {
            if(array[l] + array[r] == sum) {
                ans.push_back(array[l]);
                ans.push_back(array[r]);
                break;
            }
            else if(array[l] + array[r] < sum) {
                ++l;
            }
            else {
                --r;
            }
        }
        return ans;
    }
};