# include <vector>
# include <queue>
using namespace std;

// Problem 98
// Problem 6 of April
// Map Of Highest Peak: MEDIUM
// Date: 06/04/26
// Complexity: O(nm)

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int rows = isWater.size();
        int cols = isWater[0].size();
        
        // Initialize height matrix with -1 (unvisited)
        vector<vector<int>> height(rows, vector<int>(cols, -1));
        queue<pair<int, int>> bfsQueue;
        
        // Push all water cells as starting points with height 0
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (isWater[i][j] == 1) {
                    height[i][j] = 0;
                    bfsQueue.push({i, j});
                }
            }
        }
        
        // Four directional movement vectors
        int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        // BFS to assign heights
        while (!bfsQueue.empty()) {
            auto [currentRow, currentCol] = bfsQueue.front();
            bfsQueue.pop();
            
            int currentHeight = height[currentRow][currentCol];
            
            // Explore all 4 neighbors
            for (auto& dir : directions) {
                int newRow = currentRow + dir[0];
                int newCol = currentCol + dir[1];
                
                // If neighbor is within bounds and unvisited
                if (newRow >= 0 && newRow < rows && 
                    newCol >= 0 && newCol < cols && 
                    height[newRow][newCol] == -1) {
                    
                    // Assign height = current height + 1
                    height[newRow][newCol] = currentHeight + 1;
                    bfsQueue.push({newRow, newCol});
                }
            }
        }
        
        return height;
    }
};