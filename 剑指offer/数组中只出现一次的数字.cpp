class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {

        for(auto num : data) {
            *num1 = *num1 ^ num;
        }

        int temp = 1;
        while((*num1 & temp) == 0) {
            temp = temp << 1;
        }

        *num1 = *num2 = 0;
        for(auto num : data) {
            if((num & temp) == 0) {
                *num1 = *num1 ^ num;
            }
            else {
                *num2 = *num2 ^ num;
            }
        }
    }
};