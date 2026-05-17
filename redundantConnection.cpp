# include <vector>
using namespace std;

// Problem 73
// Problem 19 of March
// Redundant Connection: MEDIUM
// Date: 14/03/26
// Complexity: O(E)

class Solution {
public:
    vector<int> parent;

    int find(int x){
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int x, int y){
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY){
            return false;
        } 

        parent[rootY] = rootX;
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges){
        int n = edges.size();
        parent.resize(n + 1);

        for (int i = 0; i < n; i++){
            parent[i] = i;
        }

        for (auto& e: edges){
            int u = e[0];
            int v = e[1];

            if (!unite(u, v)){
                return e;
            }
        }

        return {};
    }
};