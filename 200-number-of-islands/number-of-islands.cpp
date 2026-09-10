class Solution {
private:
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& vis, int rows, int cols) {
        if(i < 0 || j < 0 || i >= rows || j >= cols || vis[i][j] || grid[i][j] != '1') {
            return;
        }

        vis[i][j] = true;

        dfs(i-1, j, grid, vis, rows, cols); // top
        dfs(i, j+1, grid, vis, rows, cols); // left
        dfs(i+1, j, grid, vis, rows, cols); // botton
        dfs(i, j-1, grid, vis, rows, cols); // right

    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;

        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        for(int i = 0; i<rows; i++) {
            for(int j = 0; j<cols; j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    dfs(i, j, grid, vis, rows, cols);
                    islands++;
                }                
            }
        }

        return islands;    
    }
};