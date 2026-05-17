# include <vector>
# include <queue>
using namespace std;

// Problem 82
// Problem 28 of March
// Swim In Rising Water: HARD
// Date: 22/03/26
// Complexity: O(n^2 log n)
// This stupid problem got me sleepless yesterning
// Anyways it is just a dikstra problem with just a twist
// We need to get to the botttom cell, as fast as possible (minHeap)
// We need the max time taken (max height encountered) to be the least
// So the only time we change the time is when the optimal path has that max level > prev levels

class Solution {
public:
    int swimWater(vector<vector<int>> &grid){
        // get size
        int n = grid.size();

        // priority queue for dijkstra
        // min heap: {waterLevel, r, c}
        // water level is basically the number at that cell

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        // visited array
        vector<vector<int>> visited(n, vector<int>(n, 0));

        // push the first cell and mark it visited
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = 1;

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!pq.empty()){
            // so here we need to minimize the maximum heights encountered
            auto top = pq.top();
            pq.pop();

            int level = top[0];
            int r = top[1];
            int c = top[2];

            // if we are at the end
            if (r == n - 1 && c == n - 1)
                return level;

            for (auto& dir : dirs){
                int nr = r + dir[0];
                int nc = c + dir[1];
                
                // out of bounds? continue
                if (nc < 0 || nr < 0 || nc >= n || nr >= n)
                    continue;
                
                // cell alr visited? continue
                if (visited[nr][nc]) 
                    continue;

                // key idea: take max height so far
                int newLevel = max(level, grid[nr][nc]);

                pq.push({newLevel, nr, nc});
            }
        }

        return -1;
        
    }
};