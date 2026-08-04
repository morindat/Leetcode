#include <iostream>
#include <vector>
using namespace std;

/*
 * Problem 199
 * Richest Customer Wealth: EASY
 * Time: 2026-08-04
 * Complexity: 0(n * m)
 */ 

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;

        for (const auto& customer: accounts) {
            int wealth = 0;

            for(int money : customer) {
                wealth += money;
            }
            maxWealth = max(wealth, maxWealth);
        }

        return maxWealth;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> accounts = {{1, 5}, {7, 3}, {3, 5}};
    int ans = sol.maximumWealth(accounts);

    cout << "The wealthiest customer has $" << ans << " in their account" << endl;

    return 0;
}
