#include <iostream>
#include <vector>
using namespace std;

/*
 * Problem 197
 * Min Cost Climbing Stairs: EASY
 * Time: 2026-08-03
 * Complexity: 0(n)
 */ 

/*
 * So we are given a vector cost where each val at ith position is the cost to make a jump at that position
 * And you can take 1 or 2 steps at a time, and our job is to minimize the cost of jumping all the way to the end 
 * And ofc this problem is solvable by quite a few methods, the most common of all is top down dp
 * We know at the begining we can take a step or two at no cost, so dp[0] and dpp[1] is 0, and then the cost is then accumulative from 
 * There on, only thing we need to do is to pick the smallest so dp[i] = min [taking one step, taking two steps]
*/

class Solution {
private:
    vector<int> memo;

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp (n + 1, 0);

        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }

        return dp[n];
    } 

    // But we definitely can space optimize this and solve it iterably

    int minCostClimbingStairsSO(vector<int>& cost) {
        int n = cost.size();
        
        int prev2 = 0; // Cost of 2 steps in the begining so your dp[i - 2]
        int prev1 = 0; // Cost of 1 step in the begining so your dp[i - 1]


        for (int i = 2; i <= n; i++) {
            int current_step = min(prev1 + cost[i - 1], prev2 + cost[i - 2]);
            prev2 = prev1;
            prev1 = current_step;
        }

        return prev1; // By the end of that loop, this will hold the current_step
    }

    // And ofcoz since we can do it bottom up, what's stopping us from doing top bottom as will

    int minCostClimbingStairsTB(vector<int>& cost) {
        int n = cost.size();
        memo.assign(n + 1, -1);
        return dp(cost, n);
    }

    int dp(vector<int>& cost, int i) {
        if (i == 0 || i == 1) return 0;

        if (memo[i] != -1) return memo[i];

        memo[i] = min(
            dp(cost, i-1) + cost[i - 1], 
            dp(cost, i -2) + cost[i - 2]
        );

        return memo[i];
    }
};

// Minimalist main

int main() {
    Solution sol;
    vector<int> cost = {10, 15, 20};

    cout << "Min cost of climbing BT: " << sol.minCostClimbingStairs(cost) << endl;
    cout << "Min cost of climbing SO: " << sol.minCostClimbingStairsSO(cost) << endl;
    cout << "Min cost of climbing TB: " << sol.minCostClimbingStairsTB(cost) << endl;
    
    return 0;
}
