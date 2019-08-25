class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return;
        int row = matrix.size(), col = matrix[0].size();
        for(int i = 0; i < row; i++) {
           vector<int> v(col, 0);
           sum.push_back(v);
           for(int j = 0; j < col; j++) {
               sum[i][j] = matrix[i][j] + (i > 0 ? sum[i-1][j] : 0) + (j > 0 ? sum[i][j-1] : 0) - (i > 0 && j > 0 ? sum[i-1][j-1] : 0);
           } 
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int row = sum.size(), col = sum[0].size();
        if(row2 >= row || col2 >= col)  return 0;
        return sum[row2][col2] - (row1 - 1 >= 0 ? sum[row1-1][col2] : 0) - (col1 - 1 >= 0 ? sum[row2][col1-1] : 0) + (row1 >= 1 && col1 >= 1 ? sum[row1-1][col1-1] : 0);
    }
private:
    vector<vector<int>> sum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */