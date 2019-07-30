/*
    左上开始遍历，遇到陆地使用dfs将其相邻的都变成'0'
 */

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        int num = 0;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    num += 1;
                }
            }
        }
        return num;
    }

    void dfs(vector<vector<char>>& grid, int x, int y) {
        grid[x][y] = '0';
        // up
        if(x - 1 >= 0 && grid[x-1][y] == '1')   dfs(grid, x-1, y);
        // down
        if(x + 1 < grid.size() && grid[x+1][y] == '1')   dfs(grid, x+1, y);
        // left
        if(y - 1 >= 0 && grid[x][y-1] == '1')   dfs(grid, x, y-1);
        // right
        if(y + 1 < grid[0].size() && grid[x][y+1] == '1')   dfs(grid, x, y+1);
    }
};