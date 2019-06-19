class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    	for(int i = 0; i <= 2; ++i) {
    		for(int j = 0; j <= 2; ++j) {
    			bool num[10] = {false};
    			for(int k = 0; k <= 8; ++k) {
    				if(board[i * 3 + k / 3][j * 3 + k % 3] != '.') {
    					if(!num[board[i * 3 + k / 3][j * 3 + k % 3] - '0']) num[board[i * 3 + k / 3][j * 3 + k % 3] - '0'] = true;
    					else return false;
    				}
    			}
    		}
    	}

    	for(int i = 0; i <= 8; ++i) {
			bool num[10] = {false};	
    		for(int j = 0; j <= 8; ++j) {
    			if(board[i][j] != '.') {
					if(!num[board[i][j] - '0']) num[board[i][j] - '0'] = true;
					else return false;
				}
    		}
    	}

    	for(int i = 0; i <= 8; ++i) {
			bool num[10] = {false};	
    		for(int j = 0; j <= 8; ++j) {
    			if(board[j][i] != '.') {
					if(!num[board[j][i] - '0']) num[board[j][i] - '0'] = true;
					else return false;
				}
    		}
    	}
    	return true;
    }
};