#include <vector>
using namespace std;

/**
 * Problem 190
 * Problem 27/45 of June 2026
 * Climbing Stairs: EASY
 * Date: 27/06/26
 * Time Complexity: O(2^n) brute force and O(n) optimized
*/

class Solution {
private:
    vector<int> memo;

    int dp(int n) {
        if (n <= 2) return n;
        if (memo[n] != -1) return memo[n];
        return memo[n] = memo[n - 1] + memo[n - 2];
    }

public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }

    int climbMemo(int n) {
        memo.assign(n + 1, -1);
        return memo[n];
    }

    int climbDP(int n) {
        if (n <= 2) return n;

        vector<int> dp(n + 1);

        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }

    int climbSCOptim(int n) {
        if (n <= 2) return n;

        int prev2 = 1;
        int prev1 = 2;

        for (int i = 3; i <= n; i++) {
            int current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};