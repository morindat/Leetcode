# include <vector>
# include <queue>
# include <algorithm>
using namespace std;

// Problem 95
// Problem 3 of April
// Trapping Rain Water II: HARD
// Date: 03/04/26
// Complexity: O(mn log mn)

class Solution {
    int trapRainWater(vector<vector<int>>& heightMap) {
        // check if mat is empty and return 0
        if (heightMap.empty() || heightMap[0].empty()){
            return 0;
        }

        // get dimensions otherwise
        int m = heightMap.size();
        int n = heightMap[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        // push all boundary cells into the heap
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1){
                    pq.push({heightMap[i][j], i, j});
                    visited[i][j] = true;
                }
            }
        }

        // directions: up, down, left, right
        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int waterTrapped = 0;
        int currentMax = INT_MIN;

        while (!pq.empty()){
            auto cell = pq.top();
            pq.pop();

            int height = cell[0];
            int i = cell[1];
            int j = cell[2];

            currentMax = max(currentMax, height);

            // check all dir
            for (auto& dir : dirs){
                int nr = i + dir[0];
                int nc = j + dir[1];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nr]){
                    // If neighbor is lower than current water level, water is trapped
                    if (heightMap[nr][nc] < currentMax){
                        waterTrapped += currentMax - heightMap[nr][nc];
                    }

                    // Push neighbor with effective height
                    pq.push({max(heightMap[nr][nc], currentMax), nr, nc});
                }
            }
        }
        return waterTrapped;
    }
};