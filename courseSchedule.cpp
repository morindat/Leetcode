# include <stack>
# include <vector>
using namespace std;

// Problem 50
// Problem 20 of Feb
// Course Schedule: MEDIUM
// Date: 24/02/26

class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& state) {
        if (state[node] == 1) return true;   // cycle detected
        if (state[node] == 2) return false;  // already processed

        state[node] = 1; // mark as visiting

        for (int neighbor : adj[node]) {
            if (dfs(neighbor, adj, state))
                return true;
        }

        state[node] = 2; // mark as processed
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        
        // build graph: b -> a
        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        vector<int> state(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                if (dfs(i, adj, state))
                    return false; // cycle exists
            }
        }

        return true; // no cycle
    }
};