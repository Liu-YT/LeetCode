class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
    	vector<vector<int>> v;
    	for(int i = 0; i < n; ++i)
    		v.push_back(vector<int>(n));

    	int q = n, num = 0;
    	for(int i = 0; i < (n+1) / 2; ++i, q -= 2) {
    		// top
    		for(int j = i; j < i + q; ++j)
    			v[i][j] = ++num;

    		// right
    		for(int j = i + 1; j < i + q; ++j)
    			v[j][i+q-1] = ++num;

    		// down
    		for(int j = i + q - 2; j >= i; --j)
    			v[i+q-1][j] = ++num;

    		// left
    		for(int j = i + q - 2; j > i; --j)
    			v[j][i] = ++num;
    	}

    	return v;
    }
};