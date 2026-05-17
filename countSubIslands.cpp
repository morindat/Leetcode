# include <vector>
# include <queue>
using namespace std;

// Problem 78
// Problem 24 of March
// Count Sub Islands: MEDIUM
// Date: 20/03/26
// Complexity: O(M * N)

class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        // Get the dimensions of the grid
        int m = grid1.size(), n = grid1[0].size();
        
        // Initialize visited array for grid and the 4 directions of the grid
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int count = 0;

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid2[i][j] == 1 and !visited[i][j]){
                    // BFS
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;
                    bool isValid = true;

                    while (!q.empty()){
                        auto [r, c] = q.front();
                        q.pop();

                        // check if this cell is land in grid1
                        if (grid1[r][c] == 0) {
                            isValid = false;
                        }

                        // explore the neightbours of that cell
                        for (auto dir : dirs){
                            int nr = r + dir[0];
                            int nc = c + dir[1];

                            // check boundaries
                            // make sure it is land in grid 2 and not visited

                            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid2[nr][nc] == 1 && !visited[nr][nc]){
                                // mark it visited and push to q
                                visited[nc][nr] = true;
                                q.push({nr, nc});
                            }
                        }
                    } 

                    if (isValid){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};