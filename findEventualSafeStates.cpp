# include <vector>
# include <queue>
# include <algorithm>
using namespace std;

// Problem 96
// Problem 4 of April
// Find Eventual Safe States: MEDIUM
// Date: 04/04/26
// Complexity: O(V + E)

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, 0); // 0: unvisited, 1: visiting, 2: safe
        
        vector<int> result;
        
        for (int i = 0; i < n; i++) {
            if (dfs(i, graph, state)) {
                result.push_back(i);
            }
        }
        
        return result;
    }
    
private:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& state) {
        // If already visited, return true if safe, false if unsafe
        if (state[node] > 0) {
            return state[node] == 2;
        }
        
        // Mark as visiting
        state[node] = 1;
        
        // Check all neighbors
        for (int neighbor : graph[node]) {
            if (!dfs(neighbor, graph, state)) {
                return false; // Found a cycle
            }
        }
        
        // Mark as safe
        state[node] = 2;
        return true;
    }
};