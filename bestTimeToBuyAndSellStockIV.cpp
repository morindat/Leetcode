#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Problem 218
 * Best Time To Buy And Sell Stock IV: HARD 
 * Date: 2026-09-30
 * Complexity: O(nk) 
 */ 

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int m = prices.size();
        k = min(k, m / 2);

        int n = 2 * k + 1;
        vector<int> dp(n, -1e9);
        dp[0] = 0;

        for (int price: prices) {
            vector<int> old = dp;
            for (int i = 1; i < n; i++) {
                if (i % 2 != 0) {
                    // Buy
                    dp[i] = max(old[i], old[i-1] - price);
                } else {
                    // Sell
                    dp[i] = max(old[i], old[i-1] + price);
                }
            }
        }

        int max_profit = 0;

        for (int i = 0; i < n; i += 2) {
            max_profit = max(max_profit, dp[i]);
        }

        return max_profit;
    }
};

int main() {
    Solution sol; 
    vector<int> prices = {3,3,5,0,0,3,1,4};
    int k = 2;

    cout << "maxProfit: " << sol.maxProfit(k, prices) << "\n";

    return 0;
}
