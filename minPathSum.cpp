#include <iostream>
#include <vector>
using namespace std;

/*
 * Problem 202
 * Minimum Path Sum: MEDIUM
 * Time: 2026-08-07  
 * Complexity: 0(m * n)
 */ 


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dp(n, 0);
        dp[0] = grid[0][0];

        // Fill the first row
        // Which is the sum of all cells from 0 to i in that row
        for (int i = 1; i < n; i++) {
            dp[i] = grid[0][i] + dp[i-1];
        }

        // Now do process the other row
        for (int i = 1; i < m; i++) {
            dp[0] += grid[i][0];

            for (int j = 1; j < n; j++) {
                dp[j] = grid[i][j] + min(dp[j], dp[j-1]);
            }
        }

        return dp[n-1];
    }
};


int main() {
    Solution sol;
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 1}, {1, 1, 1}};

    cout << "The minimum path sum is: " << sol.minPathSum(grid) << endl;

    return 0;
}
