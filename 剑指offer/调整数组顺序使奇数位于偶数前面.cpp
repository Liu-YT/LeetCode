class Solution {
public:
    void reOrderArray(vector<int> &array) {
        for(int i = 0; i < array.size(); i++) {
            for(int j = 0; j < array.size()-1; j++) {
                if((array[j] & 1) == 0) {
                    int num = array[j];
                    if(array[j+1] & 1) {
                        array[j] = array[j+1];
                        array[j+1] = num;
                    }
                }
            }
        }
    }
};