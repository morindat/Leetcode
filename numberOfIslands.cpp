# include <vector>
using namespace std;

// Problem 70
// Problem 16 of March
// No of Islands : MEDIUM
// Date: 09/03/26
// Complexity: O(rows * cols)

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c){
        int rows = grid.size();
        int cols = grid[0].size();

        // out of bounds or water
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == '0'){
            return;
        }

        // mark the cell we are looking at visited
        grid[r][c] = '0';

        // dfs the four directions
        dfs(grid, r+1, c);
        dfs(grid, r-1, c);
        dfs(grid, r, c+1);
        dfs(grid, r, c-1);
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1') {
                    islands++;
                    dfs(grid, r, c);
                }
            }
        }
        
        return islands;
    }
};