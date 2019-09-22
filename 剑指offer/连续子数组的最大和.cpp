class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int cur = array[0];
        int ans = array[0];
        
        for(int i = 1; i < array.size(); i++) {
            if(array[i] < 0) {
                ans = max(cur, ans);
                cur = max(array[i], cur + array[i]);
            }
            else {
                cur = max(array[i], cur + array[i]);            
            }
        }

        ans = max(cur, ans);
        return ans;
    }
};