class Solution {
public:
    bool IsContinuous(vector<int> numbers) {
        if(numbers.size() <= 0) {
            return false;
        }
        
        sort(numbers.begin(), numbers.end());
        
        int cnt = 0, i = 0;
        while(numbers[i] == 0) {
            ++i;
            ++cnt;
        }

        for(int j = i; j < numbers.size() - 1; j++) {
            if(numbers[j] == numbers[j+1]) {
                return false;
            }
            else if(numbers[j] == numbers[j+1] - 1) {
                continue;
            }
            else {
                cnt -= numbers[j+1] - numbers[j] - 1;
                if(cnt < 0) {
                    return false;
                }
            }
        }

        return true;
    }
};