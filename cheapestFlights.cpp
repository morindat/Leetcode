# include <vector>
# include <queue>
using namespace std;

// Problem 77
// Problem 23 of March
// Cheapest Flights Withing K Stops: MEDIUM
// Date: 17/03/26
// Complexity: O(E)

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        
        // build graph
        for (auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        queue<pair<int,int>> q; // {node, cost}
        q.push({src, 0});

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        int stops = 0;

        while (!q.empty() && stops <= k) {
            int size = q.size();
            vector<int> temp = dist;  

            for (int i = 0; i < size; i++) {
                auto [node, cost] = q.front();
                q.pop();

                for (auto &[adjNode, wt] : adj[node]) {
                    if (cost + wt < temp[adjNode]) {
                        temp[adjNode] = cost + wt;
                        q.push({adjNode, cost + wt});
                    }
                }
            }

            dist = temp;
            stops++;
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};
