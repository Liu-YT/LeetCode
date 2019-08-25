class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size(), col = board[0].size();
        vector<vector<int>> copy;
        
        for(int i = 0; i < row; i++) {
            vector<int> tmp(col);
            copy.push_back(tmp);
            for(int j = 0; j < col; j++) {
                copy[i][j] = board[i][j];
            }
        }
        
        for(int r = 0; r < row; r++) {
            for(int c = 0; c < col; c++) {
                int live = 0;
                
                for(int i = -1; i <= 1; i++) {
                    for(int j = -1; j <= 1; j++) {
                        if(i == 0 && j == 0)    continue;
                        if(r + i >= 0 && r + i < row && c + j >= 0 && c + j < col) {
                            if(copy[r+i][c+j] == 1)
                                ++live;
                        }  
                    }
                }

                if(live < 2 || live > 3)
                    board[r][c] = 0;
                if(live == 3)
                    board[r][c] = 1;
            }
        }
    }
};  