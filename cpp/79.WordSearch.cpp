// 思路比较简单，找到第一个字符，然后递归搜索

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word == "")  return true;
        if(board.size() == 0 || board[0].size() == 0)   return false;
        int a = board.size(), b = board[0].size();
        
        vector<vector<bool>> matrix;
        for(int i = 0; i < a; ++i) 
            matrix.push_back(vector<bool>(b, false));

         
        for(int i = 0; i < a; ++i) {
            for(int j = 0; j < b; ++j) {
                if(board[i][j] == word[0]) {
                    matrix[i][j] = true;
                    bool found = isFound(board, word, matrix, i, j, 1);
                    if (found == true)  return true;
                    matrix[i][j] = false;
                }
            }
        }
        return false;
    }

    bool isFound(vector<vector<char>> &board, string &word, vector<vector<bool>> &matrix, int x, int y, int curI) {
        if(curI == word.size()) return true;

        // up
        if(x - 1 >= 0 && !matrix[x - 1][y] && board[x - 1][y] == word[curI]) {
            matrix[x - 1][y] = true;
            bool found = isFound(board, word, matrix, x - 1, y, curI + 1);
            if(found == true)    return true;
            matrix[x - 1][y] = false;
        }

        // down
        if(x + 1 < board.size() && !matrix[x + 1][y] && board[x + 1][y] == word[curI]) {
            matrix[x + 1][y] = true;
            bool found = isFound(board, word, matrix, x + 1, y, curI + 1);
            if(found == true)    return true;
            matrix[x + 1][y] = false;
        }

        // right
        if(y + 1 < board[0].size() && !matrix[x][y + 1] && board[x][y + 1] == word[curI]) {
            matrix[x][y + 1] = true;
            bool found = isFound(board, word, matrix, x, y + 1, curI + 1);
            if(found == true)    return true;
            matrix[x][y + 1] = false;
        }

        
        // left
        if(y - 1 >= 0 && !matrix[x][y - 1] && board[x][y - 1] == word[curI]) {
            matrix[x][y - 1] = true;
            bool found = isFound(board, word, matrix, x, y - 1, curI + 1);
            if(found == true)    return true;
            matrix[x][y - 1] = false;
        }

        return false;
    }
};