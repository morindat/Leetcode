#include <vector>
using namespace std;

// Problem 58
// Problem 4 of March
// Island Perimeter: EASY
// Date: 04/03/26

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        // counting problem
        // add 4 for each land areas
        // check if it is connected to another land 
        // in these two directions
        // right and down, if true -2
        
        int perimeter = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){
                if (grid[r][c] == 1){
                    perimeter += 4;

                    // check right
                    if (c + 1 < cols && grid[r][c + 1] == 1){
                        perimeter -= 2;
                    }

                    // check bottom
                    if (r + 1 < rows && grid[r + 1][c] == 1){
                        perimeter -= 2;
                    }
                }
            }
        }

        return perimeter;
    }
};

// DFS
class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c){
        int rows = grid.size();
        int cols = grid[0].size();
        int perimeter = 0;

        // check boundaries
        // out of bound mean +1 to the perimeter
        if (r < 0 || r >= rows || c < 0 || c >= cols) 
            return 1;

        // check if cell is bound by water
        // means +1 too
        if (grid[r][c] == 0)
            return 1;

        // if alr visited and land, then it does not contribute nothing
        // avoid overcounting
        if (grid[r][c] == -1)
            return 0;
        
        // make the starting cell visited
        // count in all four directions
        grid[r][c] = -1;

        perimeter += dfs(grid, r + 1, c);
        perimeter += dfs(grid, r - 1, c);
        perimeter += dfs(grid, r, c + 1);
        perimeter += dfs(grid, r, c - 1);

        return perimeter;
    }

    int islandPerimeter(vector<vector<int>> grid){
        int rows = grid.size();
        int cols = grid[0].size();

        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){
                if (grid[r][c] == 1){
                    return dfs(grid, r, c);
                }
            }
        }

        return 0;
    }
};