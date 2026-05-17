# include <vector>
# include <queue>
using namespace std;

// Problem 88
// Problem 34 of March
// 01 Matrix: MEDIUM
// Date: 29/03/26
// Complexity: O(m * n)

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int rows = mat.size();
        int cols = mat[0].size();
        
        queue<pair<int,int>> q;
        
        // Step 1: push all 0s into queue
        // and mark 1s as unvisited (-1)
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                
                if (mat[i][j] == 0) {
                    q.push({i, j});
                } 
                else {
                    mat[i][j] = -1;  // mark unvisited
                }
            }
        }
        
        // 4 directions
        vector<int> dir = {0, 1, 0, -1, 0};
        
        // Step 2: BFS
        while (!q.empty()) {
            
            auto [r, c] = q.front();
            q.pop();
            
            // check all 4 neighbors
            for (int d = 0; d < 4; d++) {
                
                int nr = r + dir[d];
                int nc = c + dir[d+1];
                
                // check bounds and unvisited
                if (nr >= 0 && nc >= 0 && nr < rows && nc < cols 
                    && mat[nr][nc] == -1) {
                    
                    // distance = parent distance + 1
                    mat[nr][nc] = mat[r][c] + 1;
                    
                    q.push({nr, nc});
                }
            }
        }
        
        return mat;
    }
};