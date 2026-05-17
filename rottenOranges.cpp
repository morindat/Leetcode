#include <vector>
#include <queue>
using namespace std;

// Problem 62
// Problem 8 of March
// Rotten Oranges: MEDIUM
// Date: 06/03/26
// So now I owe February just 3 qns
// Complexity: O(m * n)

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // multi source bfs
        // keep a count of fresh oranges
        // push the rotten ones in a queue
        
        queue<pair<int,int>> q;
        int fresh = 0;
        int minutes = 0;

        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                if (grid[i][j] == 2){
                    q.push({i, j});
                }
                if (grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        // we need the foour directions
        vector<int> dr = {1, -1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};

        while(!q.empty() && fresh > 0){
            int size = q.size();

            // pop every rotten orange from queue so
            // that they can start infecting others
            // lol

            for (int i = 0; i < size; i++){
                auto [r, c] = q.front();
                q.pop();

                // calculate the new cols and row of infection spreading
                for (int d = 0; d < 4; d++){
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr,nc});
                    }
                }
            }

            minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};