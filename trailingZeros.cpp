# include <iostream>
using namespace std;

/**
 * Problem 156
 * Problem 43/45 of May 2026
 * Factorial Trailing Zeroes: MEDIUM
 * Date: 28/05/26
 * Time Complexity: O(log5 n)
*/

class Solution {

public:
    int trailingZeroes(int n) {
        int count = 0;

        // Mathematical insight here is that the trailing zeros are from the factors of 10
        // that is 2 and 5, there are always more factors of 2 than 5
        // So 5 becomes the limiting factor and hence the trailing 0s = number of factors of 5
        while (n > 0) {
            n /= 5;
            count += n;
        }

        return count;
    }
};