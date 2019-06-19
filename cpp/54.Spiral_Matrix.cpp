// 找规律，注意细节

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    	if(matrix.size() == 0 || matrix[0].size() == 0)	return {};
    	int m = matrix.size();
    	int n = matrix[0].size();
		int p = m, q = n;	
    	vector<int> v;

    	int r = min((m + 1) / 2, (n + 1) / 2);
		for(int i = 0; i < r; ++i, p -= 2, q -= 2) {
			// top
			for(int j = i; j < i + q; ++j)
				v.push_back(matrix[i][j]);

			// right
			for(int j = i + 1; j < i + p; ++j)
				v.push_back(matrix[j][i+q-1]);

			if(q == 1 || p == 1)	break;

			// down
			for(int j = i + q - 2; j >= i; --j)
				v.push_back(matrix[i+p-1][j]);

			// left
			for(int j = i + p - 2; j > i; --j)
				v.push_back(matrix[j][i]);
		}
		return v;   
    }
};