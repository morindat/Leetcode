#include <vector>
using namespace std;

// Problem 57
// Problem 3 of March
// Find If Path Exists: EASY
// Date: 04/03/26

class Solution {
public:
    bool dfs(int node, int dest, vector<vector<int>>& adj, vector<bool>& visited){
        if (node == dest) return true;

        visited[node] = true;

        for (int neigh: adj[node]){
            if (!visited[neigh]){
                if (dfs(neigh, dest, adj, visited)){
                    return true;
                }
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // build the graph
        vector<vector<int>> adj(n);

        for (auto & e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);
        return dfs(source, destination, adj, visited);
    }
};