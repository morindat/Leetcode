#include <iostream>
#include <vector>
using namespace std;

/*
 * Problem 220
 * Burst Balloons: HARD 
 * Date: 2026-10-03
 * Complexity: O(n^3) time, O(n^2) space
 */

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        // Pad the array with 1s on both ends to handle boundary balloons.
        // This avoids out-of-bounds checks: bursting an edge balloon uses
        // the virtual boundary value of 1.
        vector<int> balloons(n + 2);
        balloons[0] = 1;
        balloons[n + 1] = 1;
        for (int i = 0; i < n; i++)
            balloons[i + 1] = nums[i];

        int N = n + 2; // total size including the two virtual boundary balloons

        // dp[l][r] = max coins obtainable by bursting all balloons
        // strictly between indices l and r (exclusive boundaries).
        vector<vector<int>> dp(N, vector<int>(N, 0));

        // Iterate over all intervals of increasing length.
        // 'len' is the gap between left and right boundary (must be >= 2
        // to have at least one balloon inside).
        for (int len = 2; len < N; len++) {
            for (int l = 0; l < N - len; l++) {
                int r = l + len;

                // Try every balloon k as the LAST one burst in (l, r).
                // Because k is burst last, l and r are still present when k
                // is popped, so the coin gain is balloons[l] * balloons[k] * balloons[r].
                // The subproblems (l, k) and (k, r) are already solved and stored in dp.
                for (int k = l + 1; k < r; k++) {
                    int coins = balloons[l] * balloons[k] * balloons[r]
                                + dp[l][k] + dp[k][r];
                    dp[l][r] = max(dp[l][r], coins);
                }
            }
        }

        // The answer covers all original balloons: interval (0, N-1),
        // i.e., between the two virtual boundary balloons.
        return dp[0][N - 1];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3,1,5,8};

    cout << "Maximum Coins: " << sol.maxCoins(nums) << "\n";

    return 0;
}
