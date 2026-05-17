# include <vector>
# include <queue>
# include <string>
using namespace std;

// Problem 83
// Problem 29 of March
// Similar String Groups: HARD
// Date: 23/03/26
// Complexity: O(n^2 * m)

class Solution {
public:
    vector<int> parent;

    int find(int x){
        if (parent[x] == x){
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    bool unite(int u, int v){
        int root_u = find(u);
        int root_v = find(v);

        if (root_u != root_v){
            root_v = root_u;
        }
    }

    bool isSimilar(string& a, string& b){
        int diff = 0;

        for (int i = 0; i < a.size(); i++){
            if (a[i] != b[i])
                diff++;
            
            if (diff > 2) 
                return false;
        }

        return true;
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        parent.resize(n, 0);

        // init union find
        for (int i = 0; i < n; i++)
            parent[i] = i;

        // compare
        // and unite those that belong to the same component
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                if (isSimilar(strs[i], strs[j])){
                    unite(i, j);
                }
            }
        }

        int groups = 0;

        for (int i = 0; i < n; i++){
            if (find(i) == i){
                groups++;
            }
        }

        return groups;
    }
};