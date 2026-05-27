# include <iostream>
using namespace std;

/**
 * Problem 148
 * Problem 35/45 of May 2026
 * Power Of Two: EASY
 * Date: 27/05/26
 * Time Complexity: O(log n);
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        while (n % 2 == 0) {
            n /= 2;
        }
        return n == 1;
    }

    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        if (n == 1) return true;
        if (n % 2 != 0) return false;
        return isPowerOfTwo(n / 2);
    }
};