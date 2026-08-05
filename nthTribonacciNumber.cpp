#include <iostream>
#include <vector>
using namespace std;

/*
 * Problem 199
 * Nth Tribonacci Number: EASY
 * Time: 2026-08-04
 * Complexity: 0(n)
 */ 

class Solution {
private:
    vector<int> memo;

public:
    // Bottom UP approach
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }

        return dp[n];
    }

    int tribonacciTD(int n) {
        memo.assign(n+1, -1);
        return dp(n);
    }

    int dp(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

        if (memo[n] != -1) return memo[n];
        memo[n] = dp(n-1) + dp(n-2) + dp(n-3);

        return memo[n];
    }
};


int main() {
    Solution sol;
    int n = 10;
    int m = 11;
    int ans = sol.tribonacci(n);
    int ans2= sol.tribonacciTD(m);

    cout << "The " << n <<"-th tribonacci number is " << ans << endl;
    cout << "The " << m <<"-th tribonacci number is " << ans2 << endl;
    
    return 0;
}
