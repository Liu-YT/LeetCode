class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int ans = INT_MAX, left = 0, right = rotateArray.size()-1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            ans = min(ans, min(rotateArray[left], rotateArray[right]));
            if(rotateArray[mid] < rotateArray[right]) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }    

        return ans == INT_MAX ? 0 : ans;  
    }
};