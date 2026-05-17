# include <vector>
# include <string>
# include <algorithm>
# include <unordered_map>
using namespace std;

// Problem 80
// Problem 26 of March
// Reconstruct Itenary: HARD
// Date: 21/03/26
// Complexity: O(E log E)
// E tickets overall sorting cost, DFS traversal is O(E)
// Lmao, I just realized that today is the 80th day of 2026 and It is my 80th leetcode problem too lol
// Been slacking a bit but no body catches up with work like i do, lmao

class Solution {
private:
    unordered_map<string, vector<string>> adj;
    vector<string> result;

    void dfs(string from){
        while (!adj[from].empty()){
            // reverse sorting lets us pop the smallest lexical destination in O(1)
            string to = adj[from].back();
            adj[from].pop_back();
            dfs(to);
        }

        // add the airport after using all outgoing tickets from it
        result.push_back(from);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        adj.clear();
        result.clear();

        // build the graph
        for (auto& t: tickets){
            adj[t[0]].push_back(t[1]);
        }

        // sort
        // Sort so we can get smallest lex order using pop_back
        for (auto &it : adj) {
            sort(it.second.rbegin(), it.second.rend());
        }
        
        // start our dfs on the JFK
        dfs("JFK");

        // the itinerary is built backwards, so reverse it at the end
        reverse(result.begin(), result.end());
        return result;
    }
};