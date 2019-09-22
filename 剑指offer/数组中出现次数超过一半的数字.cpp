class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int num = numbers[0], cnt = 1;
        for(int i = 1; i < numbers.size(); i++) {
            if(num == numbers[i]) {
                cnt++;
            }
            else {
                cnt--;
            }

            if(cnt == 0) {
                num = numbers[i];
                cnt = 1;
            }
        }

        cnt = 0;
        for(int i = 0; i < numbers.size(); i++) {
            if(numbers[i] == num)
                ++cnt;
        }

        if(cnt * 2 > numbers.size()) {
            return num;
        }

        return 0;
    }
};