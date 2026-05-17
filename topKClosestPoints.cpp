# include <vector>
# include <queue>
using namespace std;

// Problem 32
// Problem 3 of Feb
// K Closest Points: MEDIUM
// Date: 02/02/26

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        // max heap: (distance, (x, y))
        priority_queue<pair<int, pair<int,int>>> pq;

        for (auto &p : points) {
            int x = p[0], y = p[1];
            int dist = x*x + y*y;

            pq.push({dist, {x, y}});

            // keep only k closest
            if (pq.size() > k) {
                pq.pop();   // removes the farthest
            }
        }

        vector<vector<int>> res;
        while (!pq.empty()) {
            auto top = pq.top();
            res.push_back({top.second.first, top.second.second});
            pq.pop();
        }

        return res;
    }
};
