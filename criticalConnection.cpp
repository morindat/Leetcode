# include <vector>
using namespace std;

// Problem 84
// Problem 30 of March
// Critical Connection In A Network: HARD
// Date: 24/03/26
// Complexity: O(V + E)

class Solution {
public:
    vector<vector<int>> result;   // stores all critical connections (bridges)
    vector<int> disc, low;        // discovery time & lowest reachable time
    vector<vector<int>> adj;      // adjacency list
    int time = 0;                 // global timer for DFS order

    void dfs(int u, int parent) {
        // set discovery time and low value
        disc[u] = low[u] = time++;

        // explore all neighbors
        for (int v : adj[u]) {

            // ignore the edge going back to parent
            if (v == parent) continue;

            // if neighbor not visited → DFS
            if (disc[v] == -1) {

                dfs(v, u);

                // after DFS, update low value
                // can we reach an ancestor through v?
                low[u] = min(low[u], low[v]);

                // BRIDGE CONDITION
                // if v cannot reach u or any ancestor of u
                // then removing u-v disconnects graph
                if (low[v] > disc[u]) {
                    result.push_back({u, v});
                }
            } 
            else {
                // back edge found
                // update low using discovery time of v
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        // build adjacency list
        adj.resize(n);
        for (auto &e : connections) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // initialize arrays
        disc.assign(n, -1);   // -1 means unvisited
        low.assign(n, -1);

        // start DFS from node 0
        dfs(0, -1);

        return result;
    }
};