# include <vector>
# include <queue>
using namespace std;

// Problem 89
// Problem 35 of March
// Is Graph Bipartile?: MEDIUM
// Date: 29/03/26
// Complexity: O(V + E)

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        // color array
        // -1 = uncolored
        // 0 and 1 are the two colors
        vector<int> color(n, -1);
        
        // we must check all components
        for (int start = 0; start < n; start++) {
            
            // if already colored skip
            if (color[start] != -1) continue;
            
            queue<int> q;
            
            // start coloring
            q.push(start);
            color[start] = 0;
            
            while (!q.empty()) {
                
                int node = q.front();
                q.pop();
                
                // check neighbors
                for (int neighbor : graph[node]) {
                    
                    // if not colored
                    if (color[neighbor] == -1) {
                        
                        // color opposite
                        color[neighbor] = 1 - color[node];
                        
                        q.push(neighbor);
                    }
                    
                    // if same color -> not bipartite
                    else if (color[neighbor] == color[node]) {
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};

// DFS
class Solution {
public:
    
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& color) {
        
        for (int neighbor : graph[node]) {
            
            // if uncolored
            if (color[neighbor] == -1) {
                
                // color opposite
                color[neighbor] = 1 - color[node];
                
                if (!dfs(neighbor, graph, color))
                    return false;
            }
            
            // conflict
            else if (color[neighbor] == color[node]) {
                return false;
            }
        }
        
        return true;
    }
    
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> color(n, -1);
        
        for (int i = 0; i < n; i++) {
            
            if (color[i] == -1) {
                color[i] = 0;
                
                if (!dfs(i, graph, color))
                    return false;
            }
        }
        
        return true;
    }
};