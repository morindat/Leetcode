# include <vector>
# include <queue>
using namespace std;

// Problem 97
// Problem 5 of April
// As Far From Land As Possible: MEDIUM
// Date: 05/04/26
// Complexity: O(n^2)

class Solution{
public: 
    int maxDistance(vector<vector<int>>& grid){
        // get the dimension of the grid
        int n = grid.size();

        // initialize the distance vector and bfs queue
        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int> (n, -1));

        // push in all the land cells first
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 1){
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        // if the queue is empty or the size is n * n
        // means either nothing or the whole grid is land, so do nothing

        if (q.empty() || q.size() == n * n){
            return -1;
        }

        // we need to bfs all 4 directions and keep track of the max dist as well
        vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int maxDist = 0;

        // now bfs logic
        while (!q.empty()){
            // take note of the the front
            auto [ind_i, ind_j] = q.front();
            q.pop();

            for (auto [dir_i, dir_j] : dirs){
                int new_i = dir_i + ind_i;
                int new_j = dir_j + ind_j;

                // make sure they are within boundaries
                // and they are not visited meaning dist = -1
                // and they are water cells

                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n && 
                    grid[new_i][new_j] == 0 && dist[new_i][new_j] == -1){
                        // update the distance of the new cells
                        dist[new_i][new_j] = dist[ind_i][ind_j] + 1;
                        maxDist = max(maxDist, dist[new_i][new_j]);
                        
                        // push the new cell to queue
                        q.push({new_i, new_j});
                }
            }
        }

        return maxDist;
    }
};