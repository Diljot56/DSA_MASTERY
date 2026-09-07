class Solution {
public:
    void dfs(vector<vector<int>> &grid, int r, int c, int &area){
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()){
            return;
        }
        if(grid[r][c] == 0)return;
        grid[r][c] = 0;
        area++;
        dfs(grid, r + 1, c, area);
        dfs(grid, r - 1, c, area);
        dfs(grid, r, c + 1, area);
        dfs(grid, r, c - 1, area);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                int area = 0;
                if(grid[i][j] == 1){
                    dfs(grid, i, j, area);
                    maxi = max(maxi, area);
                }
            }
        }
        return maxi;
    }
};
