class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int i = 0;
        vector<int> ans;
        while(i < min((row + 1) / 2, (col + 1) / 2)) {
            // up
            for(int j = i; j < col - i; j++) {
                ans.push_back(matrix[i][j]);
            }

            // right
            for(int j = i + 1; j < row - i; j++) {
                ans.push_back(matrix[j][col - i - 1]);
            }

            if((col - i - 1) == i || i == (row - i - 1)) {
                break;
            }

            // down
            for(int j = col - i - 2; j >= i; j--) {
                ans.push_back(matrix[row - i - 1][j]);
            }

            // left
            for(int j = row - i - 2; j > i; j--) {
                ans.push_back(matrix[j][i]);
            }

            ++i;
        }

        return ans;
        
    }
};