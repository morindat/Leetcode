#include <iostream>
#include <vector>
using namespace std;

/*
 * Problem 201
 * Unique Path: MEDIUM
 * Time: 2026-08-06 
 * Complexity: 0(m * n)
 */ 

/*
 * A robot is on m * n grid. It starts at the top left corner (0,0)
 * And want to reach the bottom-right (m-1, n-1)
 * The robot moves down or right at any moment, so how many unique paths is there??
 *
 * Intuition:
 * The number of ways to reach any cell i, j is exactly the sum of ways to reach the cell above it
 * (i-1, j) and the cell to the left (i, j-1) because a robot can only arrive at (i, j) from those two directions
 * So by now you should see a beautiful dynamic pattern here 
 * dp[i][j] = dp[i-1][j] + dp[i][j-1] 
 * Base case: any cell in the first row (0, j) has only one way to reach it (you can not from the top)
 * And similary any cell at the first colomn has one way to reach it 
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        // 1D array representing the current row, and inti to 1, the first row is all 1s
        vector<int> dp(n, 1);

        // Start from row 1 since row 0 is already 1s
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] = dp[j] + dp[j-1];
            }
        } 

        return dp[n-1];
    }
};


int main() {
    Solution sol;

    cout << sol.uniquePaths(3, 7) << endl;  
    cout << sol.uniquePaths(3, 3) << endl;  
    cout << sol.uniquePaths(1, 1) << endl;  

    return 0;
}
