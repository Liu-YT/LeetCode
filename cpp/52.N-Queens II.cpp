class Solution {
public:
    int totalNQueens(int n) {
    	vector<vector<string>> ans;
    	int pos[n];
    	placeQueue(pos, 0, n, ans);
    	return ans.size();
    }

    void placeQueue(int *position, int row, int n, vector<vector<string>> &ans) {
    	if(row == n) {
    		// 生成解
			vector<string> v;	
    		for(int i = 0; i < n; ++i) {
    			string str = "";
    			for(int j = 0; j < n; ++j) {
    				if(j == position[i])
    					str += "Q";
    				else
    					str += ".";
    			}
    			v.push_back(str);
    		}
    		ans.push_back(v);
    	} 
    	else {
    		// 放置皇后
    		for(int i = 0; i < n; ++i) {
    			if(isValid(position, row, i)) {
    				position[row] = i;
    				placeQueue(position, row+1, n, ans);
    			}
    		}
    	}
    }

    bool isValid(int *position, int row, int col) {
    	for(int i = 0; i < row; ++i) {
    		// 同一列
    		if(position[i] == col)	return false;
    		// 对角线
    		if(abs(row - i) == abs(col - position[i])) return false;
    	}
    	return true;
    }
};