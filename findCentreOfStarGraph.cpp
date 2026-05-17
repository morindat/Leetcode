#include <vector>
using namespace std;

// Problem 59
// Problem 5 of March
// Find The Cetre of Star Graph: EASY
// Date: 05/03/26

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // initial thought
        // count the deg of each node
        // center node will have n - 1 nodes connected to it
        // however this is an overkill, the problem is insanely simple
        // note for [1, 2] and [2, 3], the center is 2
        // so the center is always connected to some node, so it is not a necessity to check all nodes
        // the first two will sufice
        // so check if a == c or a == d for [a, b] and [c, d] then a, otherwise b

        if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1])
            return edges[0][0];
            
        return edges[0][1];
    }
};