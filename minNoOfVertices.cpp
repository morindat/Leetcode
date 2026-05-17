# include <vector>
using namespace std;

// Problem 66
// Problem 12 of March
// Minimum Number of Vertices to Reach All Nodes: MEDIUM
// Date: 07/03/26
// Complexity: O(V + E)
// O(E) to build the indegrees
// O(V) to scan the graph

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {

        // count the indegree for all nodes
        vector<int> indegree(n, 0);
        vector<int> res;

        for (auto &e : edges) {
            int from = e[0];
            int to = e[1];
            indegree[to]++;
        }

        // all the nodes with 0 indegree are the ones unreachable from other nodes
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                res.push_back(i);
            }
        }

        return res;
    }
};