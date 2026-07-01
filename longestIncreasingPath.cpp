# include <vector>
using namespace std;

// Problem 93
// Problem 1 of April
// Longest Increasing Path in a Matrix: HARD
// Date: 01/04/26
// Complexity: O(nm)
// New month, new trick: A dfs + memoization solution, never saw this coming

class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int dfs(vector<vector<int>> &matrix, int r, int c){
        if (dp[r][c] != -1) return dp[r][c];

        // a placeholder for the max length posible
        // initially 1, coz starting at any possition, the max len is just 1
        int best = 1;

        for (auto dir : dirs){
            int nr = r + dir[0];
            int nc = c + dir[1];

            // make sure they are within bounds
            // and the next cell is greater ofcoz
            if (nr < n && nc < m && nr >= 0 && nc >= 0 && matrix[nr][nc] > matrix[r][c]){
                best = max(best, 1 + dfs(matrix, nr, nc));
            }
        }

        // and what we need to return is just the dp of the best
        return dp[r][c] = best;

    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();

        // fill the dp with all -1
        dp.assign(n, vector<int> (m, -1));
        
        // initialize the ans
        int ans = 0;

        // loop and run dfs
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                ans = max(ans, dfs(matrix, i, j));
            }
        }

        return ans;
    }
};
