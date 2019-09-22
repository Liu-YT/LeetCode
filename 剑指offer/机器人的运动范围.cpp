class Solution {
public:
    int movingCount(int threshold, int rows, int cols) {
        vector<vector<bool>> used(rows, vector<bool>(cols, false));

        return helper(0, 0, rows, cols, threshold, used);
    }

    int helper(int i, int j, int rows, int cols, int threshold, vector<vector<bool>>& used) {
        if(i < 0 || i >= rows || j < 0 || j >= cols || sum(i) + sum(j) > threshold || used[i][j] == true) {
            return 0;
        }

        used[i][j] = true;
        return 1 + helper(i, j + 1, rows, cols, threshold, used) +
               helper(i, j - 1, rows, cols, threshold, used) +
               helper(i + 1, j, rows, cols, threshold, used) +
               helper(i - 1, j, rows, cols, threshold, used);
    }

    int sum(int num) {
        int tmp = 0;
        while(num) {
            tmp += num % 10;
            num = num / 10;
        }
        return tmp;
    }
};