class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

    	/*
    	*	path[i][j] = path[i-1][j] + path[i][j-1]
    	*/

        int path[obstacleGrid.size()][obstacleGrid[0].size()];

        for(int i = 0; i < obstacleGrid.size(); ++i)
			if(!obstacleGrid[i][0])	
        		path[i][0] = i >= 1 ? path[i-1][0] : 1;
        	else
        		path[i][0] = 0;

        for(int j = 0; j < obstacleGrid[0].size(); ++j)
			if(!obstacleGrid[0][j])
        		path[0][j] = j >= 1 ? path[0][j-1] : 1;
        	else
        		path[0][j] = 0;

        for(int i = 1; i < obstacleGrid.size(); ++i)
        	for(int j = 1; j < obstacleGrid[0].size(); ++j)
    			if(!obstacleGrid[i][j])
        			path[i][j] = path[i-1][j] + path[i][j-1];
        		else
        			path[i][j] = 0;

    	return path[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};