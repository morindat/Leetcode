#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Problem 217
 * Best Time To Buy And Sell Stock III: HARD 
 * Date: 2026-09-30
 * Complexity: O(n) 
 */ 


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[0] = nothing done
        // dp[1] = holding first stock
        // dp[2] = first transaction complete
        // dp[3] = holding second stock
        // dp[4] = second transaction complete 

        vector<int> dp(5, -1e9);
        dp[0] = 0;

        for (int price: prices) {
            vector<int> old = dp;

            dp[0] = old[0];
            dp[1] = max(old[1], old[0] - price);
            dp[2] = max(old[2], old[1] + price);
            dp[3] = max(old[3], old[2] - price);
            dp[4] = max(old[4], old[3] + price);
        }

        return max({dp[0], dp[2], dp[4]});
    }
};

int main() {
    Solution sol; 
    vector<int> prices = {3,3,5,0,0,3,1,4};

    cout << "maxProfit: " << sol.maxProfit(prices) << "\n";

    return 0;
}
