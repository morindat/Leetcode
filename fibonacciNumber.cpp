# include <iostream>
using namespace std;

/**
 * Problem 147
 * Problem 34/45 of May 2026
 * Fibonacci Number: EASY
 * Date: 27/05/26
 * Time Complexity: O(n);
*/

class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;

        int prev = 1;
        int prev2 = 0;

        for (int i = 2; i <= n; i++){
            int curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};