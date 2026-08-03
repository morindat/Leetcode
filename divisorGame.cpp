#include <iostream>
#include <vector>
using namespace std;

/*
 * Problem 198
 * Divisor Game: EASY
 * Time: 2026-08-03
 * Complexity: 0(n)
 */ 

/*
 * So Alice and Bob are playing a Game
 * They have to choose numbers 0 < x < n 
 * Where their choice must be such that n % x = 0 and the above condition hold
 * Alice goes first, return true if Alice can int
 * Next iteration n -= x (choice of either of them)
*/

class Solution {
public:
    bool divisorGame(int n) {
        vector<bool> dp(n + 1, false);

        for (int i = 1; i <= n; i++) {
            for (int x = 1; x < i; x++) {
                if (i % x == 0 && !dp[i - x]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }

    // This also has a nive mathematical Solution
    bool divisorGameMathematical(int n) {
        return n % 2 == 0;
    }
};



int main() {
    Solution sol;
    
    cout << boolalpha;  // print true/false instead of 1/0
    
    cout << "n=2: " << sol.divisorGame(2) << endl; 
    cout << "n=3: " << sol.divisorGame(3) << endl;

    return 0;
}
