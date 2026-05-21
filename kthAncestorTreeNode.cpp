# include <vector>
# include <iostream>
using namespace std;

/**
 * Problem 131
 * Problem 18/45 of May 2026
 * Kth Ancestor of a Tree Node: HARD
 * Date: 21/05/26
 * Time Complexity: O(n log n);
 */

class TreeAncestor {
private:
    vector<vector<int>> dp;
    int LOG;

public:
    TreeAncestor(int n, vector<int>& parent) {
        // calculate LOG = ceil (log2(n) + 1)
        LOG = 0;

        while ((1 << LOG) <=n) {
            LOG++;
        }

        // init the dp with -1
        dp = vector<vector<int>>(n, vector<int>(LOG, -1));

        // base case: the first ancestor (2^0)
        for (int i = 0; i < n; i++) {
            dp[i][0] = parent[i];
        }

        // fill up the table
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                if (dp[i][j-1] != -1) {
                    // key thing here is that
                    // the 2^j-th ancestor of a node is the 2^j-1-th ancestor of its 2^j-1-th ancestor
                    // bullshit, right? i thought so too!
                    // but think of it this, way the second ancestor of a node, is the first 
                    // ancestor of the first ancestor of that node
                    // dp[5][0] = dp[4][0] 
                    dp[i][j] = dp[dp[i][j-1]][j-1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int j = 0; j < LOG; j++) {
            // check if the jth bit of k is one
            if (k & (1 << j)) {
                // jump to 2^j steps
                node = dp[node][j];
                if (node == -1) {
                    return -1;
                }
            }
        }
        return node;
    }
};