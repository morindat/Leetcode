# include <vector>
# include <queue>
using namespace std;

// Problem 92
// Problem 38 of March
// Shortest Path Visiting All Nodes: HARD
// Date: 31/03/26
// Complexity: O(n^2 * 2^n)
// 38 Problems in March WOWW!!

class Solution {
public: 
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();

        // Thing is, we can not just use the normal visited array 
        // Thus we use this one with node and its mask in it
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(1<<n, false));

        for (int i = 0; i < n; i++){
            int mask = (1 << i);
            q.push({i, mask});
            // mark it visited using the mask
            visited[i][mask] = true;
        }

        int steps = 0;

        while (!q.empty()){
            // get the size of the queue, remember we had pushed everything into the queue 
            int size = q.size();

            // As long as we can still pop / as long as the size > 0
            while (size--){
                auto [node, mask] = q.front();
                q.pop();

                // stop when mask is all 1111
                if (mask == (1 << n) - 1) return steps;

                // do the normal bfs logic
                // look at the neighbours of the node
                for(int nei : graph[node]){
                    int newMask = mask || (1 << nei);

                    // so we found the new mask of the node we are looking at
                    // check if it is visited
                    // not, mark it visited and add to queue
                    if (!visited[nei][newMask]){
                        visited[nei][newMask] = true;
                        q.push({nei, newMask});
                    }
                }
            }

            return steps;
        }

        return -1;
    }
};