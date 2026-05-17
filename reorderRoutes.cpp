# include <vector>
# include <queue>
using namespace std;

// Problem 91
// Problem 37 of March
// Reorder Routes To Make All Paths Lead To City 0: MEDIUM
// Date: 30/03/26
// Complexity: O(n)

class Solution {
public:
    int dfs(int node, vector<vector<pair<int, int>>>&adj, vector<int> &visited){
        visited[node] = 1;
        int costs = 0;

        for (auto &[neigh, cost]: adj[node]){
            if (!visited[neigh])
                costs += cost + dfs(neigh, adj, visited);
        }

        return costs;
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        // build the graph

        vector<vector<pair<int, int>>> adj(n);

        for (auto &e : connections){
            int u = e[0], v = e[1];

            // add connection with weight
            // og direction has weight one, probably need to change
            // new direction has weight 0
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
        }

        vector<int> visited(n, 0);
        return dfs(0, adj, visited);
    }
};

// bfs approach

class BFS {
    int minReorder(int n, vector<vector<int>>& connections) {
        // build the graph once again
        vector<vector<pair<int, int>>> adj(n);

        for (auto& cn : connections){
            int u = cn[0], v = cn[u];

            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
        }

        vector<int> visited(n, 0);
        queue<int> q;
        int costs = 0;
        q.push(0);
        visited[0] = 1;

        while (!q.empty()){
            auto node = q.front();

            // for each neighbour of node
            for (auto& [neigh, cost] : adj[node]){
                // if not visited
                if (!visited[neigh]){
                    // mark it visited and include its cost to total costs 
                    visited[neigh] = 1;
                    costs += cost;
                    // push it to queue
                    q.push(neigh);
                }
            }
        }

        return costs;
    }
};