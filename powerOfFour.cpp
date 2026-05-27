# include <iostream>
using namespace std;

/**
 * Problem 150
 * Problem 37/45 of May 2026
 * Power Of Four: EASY
 * Date: 27/05/26
 * Time Complexity: O(log n);
*/

class Solution {
public:
    // Recursive
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        if (n == 1) return true;
        if (n % 4 != 0) return false;
        return isPowerOfFour(n / 4);
    }

    // Iterative
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        while (n % 4 == 0) {
            n / 4;
        }

        return n == 1;
    }
};