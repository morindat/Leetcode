#include <vector>
using namespace std;

/**
 * Problem 192
 * Problem 29/45 of June 2026
 * Best Time To Buy And Sell Stocks: EASY
 * Date: 28/06/26
 * Time Complexity: O(n) 
*/

class Solution {
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }

            maxProfit = max(maxProfit, prices[i] - minPrice);
        }

        return maxProfit;
    }
};