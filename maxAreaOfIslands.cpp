# include <vector>
# include <string>
# include <unordered_map>
# include <unordered_set>
using namespace std;

// Problem 72
// Problem 18 of March
// Max Area of Island : MEDIUM
// Date: 11/03/26
// Complexity: O(V * E)

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c){
        int rows = grid.size();
        int cols = grid[0].size();

        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0) return 0;

        // mark the first cell visited;
        grid[r][c] = 0;

        // dfs the graph
        return 1 + dfs(grid, r + 1, c) 
                 + dfs(grid, r - 1, c) 
                 + dfs(grid, r, c + 1) 
                 + dfs(grid, r, c - 1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()){
            return 0;
        }

        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;

        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){
                if (grid[r][c] == 1){
                    maxArea = max(maxArea, dfs(grid, r, c));
                }
            }
        }

        return maxArea;
    }
};