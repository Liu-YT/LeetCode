
// 旋转90°，原第i列变成第i行，第i行变成第n-i-1列
/*
	[i, j] -> [j, n - i - 1]
*/


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    	int n = matrix.size(), a, b, c, d;
    	for(int i = 0; i < n / 2; ++i) {
    		for(int j = i; j < n - i - 1; ++j) {
    			a = matrix[i][j];
    			b = matrix[j][n-i-1];
    			c = matrix[n-i-1][n-j-1];
    			d = matrix[n-j-1][i];
    			matrix[i][j] = d;
    			matrix[j][n-i-1] = a;
    			matrix[n-i-1][n-j-1] = b;
    			matrix[n-j-1][i] = c;
    		}
    	}
    }
};

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    	int n = matrix.size(), a;
    	for(int i = 0; i < n / 2; ++i) {
    		for(int j = i; j < n - i - 1; ++j) {
    			a = matrix[i][j];
    			matrix[i][j] = matrix[n-j-1][i];
    			matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
    			matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
    			matrix[j][n-i-1] = a;
    		}
    	}
    }
};