# include <vector>
# include <queue>
using namespace std;

// Problem 87
// Problem 33 of March
// Minimum Height Trees: MEDIUM
// Date: 29/03/26
// Complexity: O(n)

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        // special case: single node tree
        if (n == 1) {
            return {0};
        }
        
        // adjacency list
        vector<vector<int>> adj(n);
        
        // degree of each node
        vector<int> degree(n, 0);
        
        // build graph
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
            degree[u]++;
            degree[v]++;
        }
        
        // queue for leaves
        queue<int> q;
        
        // push all leaves (degree = 1)
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }
        
        // remaining nodes
        int remaining = n;
        
        // remove leaves layer by layer
        while (remaining > 2) {
            
            int size = q.size();
            remaining -= size;
            
            // remove current leaves
            while (size--) {
                int leaf = q.front();
                q.pop();
                
                // reduce neighbor degrees
                for (int neighbor : adj[leaf]) {
                    degree[neighbor]--;
                    
                    // if neighbor becomes leaf
                    if (degree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }
        
        // remaining nodes are centroids
        vector<int> result;
        
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }
        
        return result;
    }
};