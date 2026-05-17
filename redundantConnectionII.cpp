# include <vector>
using namespace std;

// Problem 81
// Problem 27 of March
// Reconstruct Itenary: HARD
// Date: 21/03/26
// Complexity: O(n)
// Find() -> amortized cost of 0(1)
// Unite() -> Cost: calls find() twice so just O(1)
// Main() -> O(n) for union find and detecting double parents

class Solution {
public:
    // Detect two parents + Union Find soln
    // Parent vector for union find
    vector<int> parent;

    // Normal find with path compression
    int find(int x){
        if (parent[x] == x){
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    // Normal union for cycle detection
    bool unite(int x, int y){
        int root_x = find(x);
        int root_y = find(y);

        if (root_x == root_y){
            return false;
        }

        parent[root_y] = root_x;
        return true;
    }


    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        // Now we have two problems to deal with
        // 1. Two parents for a single node

        vector<int> indegree(n + 1, 0);
        vector<int> cand1, cand2;

        // detect node with two parents
        for (auto& e: edges){
            int u = e[0];
            int v = e[1];

            if (indegree[v] == 0){
                indegree[v] = u;
            } else {
                cand1 = {indegree[v], v};  // first parent edge
                cand2 = e;                // second parent edge
                e[1] = 0;                // invalidate second edge
            }
        }

        // Init union find
        parent.resize(n + 1);
        
        for (int i = 0; i <= n; i++){
            parent[i] = i;
        }

        // 2. Detecting Cycle
        for (auto& e: edges){
            int u = e[0];
            int v = e[1];

            if (v == 0) continue;

            if (!unite(u, v)){
                // cycle found

                // if cand1 is empty
                // means no two parents for that node
                // so return the edge
                if (cand1.empty()){
                    return e;
                }
                
                // return the edge causing two parents
                return cand1;
            }
        }

        // no cycle → remove second parent
        return cand2;
    }
};
