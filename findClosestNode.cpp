# include <vector>
# include <climits>
using namespace std;

// Problem 64
// Problem 10 of March
// Find Closest Node To Given Two Nodes: MEDIUM
// Date: 06/03/26
// Complexity: O(n)

class Solution {
public:
    vector<int> getDist(vector<int>& edges, int start){
        int n = edges.size();
        // initialize the distances array to -1
        vector<int> dist(n, -1);

        // the distance updator
        int d = 0;
        int node = start;

        // while the distance of the node is -1
        // and the node itself is not -1
        // update its distance

        while (node != -1 && dist[node] == -1){
            dist[node] = d++;
            node = edges[node];
        }

        return dist;
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();

        // get the distances of each nodes from the given nodes
        vector<int>dist1 = getDist(edges, node1);
        vector<int>dist2 = getDist(edges, node2);

        // assume the best so far is some large number
        // and the node is -1
        int ans = -1;
        int best = INT_MAX;

        // loop 
        // if the dist at i for each dist from each node is not -1
        // the current best is max of those dist
        // if current is less than the best
        // best now is current
        // and ans is the node we are looking at

        for (int i = 0; i < n; i++){
            if (dist1[i] != -1 && dist2[i] != -1){
                int curr = max(dist1[i], dist2[i]);

                if (curr < best){
                    best = curr;
                    ans = i;
                }
            }
        }

        return ans;
    }
};