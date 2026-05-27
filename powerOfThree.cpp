# include <iostream>
using namespace std;

/**
 * Problem 149
 * Problem 36/45 of May 2026
 * Power Of Three: EASY
 * Date: 27/05/26
 * Time Complexity: O(log n);
*/

class Solution {
public:
    // Recursive
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        if (n == 1) return true;
        if (n % 3 != 0) return false;
        return isPowerOfThree(n / 3);
    }

    // Iterative
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        while (n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
};