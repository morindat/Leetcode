# include <vector>
# include <string>
# include <unordered_map>
# include <unordered_set>
using namespace std;

// Problem 71
// Problem 17 of March
// Evaluate Division : MEDIUM
// Date: 11/03/26
// Complexity: O(Q * (V + E))
// Each dfs is O(V + E)
// For Q queries, that makes it Q * (V + E) total running time
// I will have to run this a couple times again, the most difficult graph problem yet

class Solution {
public:
    
    double dfs(string curr, string target,
               unordered_map<string, vector<pair<string,double>>> &graph,
               unordered_set<string> &vis,
               double product) {
        
        if (curr == target) return product;
        
        vis.insert(curr);
        
        for (auto &nei : graph[curr]) {
            string next = nei.first;
            double weight = nei.second;
            
            if (!vis.count(next)) {
                double res = dfs(next, target, graph, vis, product * weight);
                if (res != -1.0) return res;
            }
        }
        
        return -1.0;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        
        unordered_map<string, vector<pair<string,double>>> graph;
        
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];
            
            graph[a].push_back({b, val});
            graph[b].push_back({a, 1.0/val});
        }
        
        vector<double> res;
        
        for (auto &q : queries) {
            string start = q[0];
            string end = q[1];
            
            if (!graph.count(start) || !graph.count(end)) {
                res.push_back(-1.0);
                continue;
            }
            
            unordered_set<string> vis;
            res.push_back(dfs(start, end, graph, vis, 1.0));
        }
        
        return res;
    }
};