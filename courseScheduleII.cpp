# include <stack>
# include <vector>
# include <algorithm>
using namespace std;

// Problem 51
// Problem 21 of Feb
// Course Schedule II: MEDIUM
// Date: 25/02/26

class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int> &state, vector<int> &order){
        if (state[node] == 1) return true;
        if (state[node] == 2) return false;

        state[node] = 1;

        for (int next: adj[node]){
            if (dfs(next, adj, state, order)){
                return true;
            }
        }

        state[node] = 2;
        order.push_back(node);

        return false;

    }


    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        // build a graph from bi to ai
        for(auto p : prerequisites){
            adj[p[1]].push_back(p[0]);
        }

        vector<int> state(numCourses, 0);
        vector<int> order;

        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                if (dfs(i, adj, state, order))
                    return {}; // cycle
            }
        }

        reverse(order.begin(), order.end());
        
        return order;
    }
};