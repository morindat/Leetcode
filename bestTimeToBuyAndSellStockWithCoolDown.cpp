#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Problem 208
 * Best TIme To Buy And Sell Stock With Cooldown: MEDIUM
 * Time: 2026-08-18
 * Complexity: O(n) 
 */ 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        // Three states:
        // hold: max profit while holding a stock
        // sold: max profit after selling (must cooldown next day)
        // rest: max profit while not holding and can buy

        int hold = prices[0];  // bought on day 0
        int sold = 0;           // can't sell on day 0
        int rest = 0;           // resting on day 0

        for (int i = 1; i < prices.size(); i++) {
            int prevHold = hold;
            int prevSold = sold;
            int prevRest = rest;

            // Can hold by: keeping previous hold, or buying today from rest state
            hold = max(prevHold, prevRest - prices[i]);

            // Can only sell if we were holding
            sold = prevHold + prices[i];

            // Can rest by: staying in rest, or cooldown after selling
            rest = max(prevRest, prevSold);
        }

        // Answer is max of sold or rest (can't end while holding)
        return max(sold, rest);
    }
};

int main() {
    Solution sol;
    vector<int> prices = {1,2,3,0,2};

    cout << "Max profit: " << sol.maxProfit(prices) << endl;

    return 0;
}
