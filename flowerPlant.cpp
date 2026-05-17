# include <vector>
using namespace std;

// Problem 85
// Problem 31 of March
// Flower Planting Without Adjacent: MEDIUM
// Date: 25/03/26
// Complexity: O(n)
// Greedy Solution

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        // build graph
        // undirected
        vector<vector<int>> adj(n);
        for (auto &p : paths) {
            int u = p[0] - 1;
            int v = p[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            bool used[5] = {false}; // flowers 1..4

            // mark neighbor colors
            for (int nei : adj[i]) {
                used[ans[nei]] = true;
            }

            // assign first available
            for (int flower = 1; flower <= 4; flower++) {
                if (!used[flower]) {
                    ans[i] = flower;
                    break;
                }
            }
        }

        return ans;
    }
};