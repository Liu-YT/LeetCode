/* solution 1 */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

  		int path[triangle.size()][triangle[triangle.size()-1].size()];

  		path[0][0] = triangle[0][0];

  		for(int i = 1; i < triangle.size(); ++i) {
  			for(int j = 0; j < triangle[i].size(); ++j) {
  				path[i][j] = INT_MAX;
  				if(j - 1 >= 0) path[i][j] = path[i-1][j-1];	
				if(j < triangle[i-1].size())
					path[i][j] = min(path[i-1][j], path[i][j]); 
				path[i][j] += triangle[i][j];
  				// cout << path[i][j] << " ";
  			}
  			// cout << endl;
  		}

  		int min = INT_MAX;
  		for(int i = 0; i < triangle[triangle.size()-1].size(); ++i)
  			if(path[triangle.size()-1][i] < min)
  				min = path[triangle.size()-1][i];

		return min;
    }
};


/*  solution 2 */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

  		int path[triangle.size()][triangle[triangle.size()-1].size()];

  		path[0][0] = triangle[0][0];

		for(int j = triangle[triangle.size() - 1].size() - 1; j >= 0; --j) {
			path[triangle.size() - 1][j] = triangle[triangle.size() - 1][j];
		}

  		for(int i = triangle.size() - 2; i >= 0; --i) {
  			for(int j = triangle[i].size() - 1; j >= 0; --j) {
				path[i][j] = min(path[i+1][j+1], path[i+1][j]) + triangle[i][j];
  				// cout << path[i][j] << " ";
  			}
  			// cout << endl;
  		}
		return path[0][0];
    }
};