# include <climits>
using namespace std;

/**
 * Problem 151
 * Problem 38/45 of May 2026
 * Power (x, n): EASY
 * Date: 27/05/26
 * Time Complexity: O(log n);
*/

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        
        // Handle negative
        if (n < 0) {
            x = 1.0 / x;
            // Prevent overflow when n = INT_MIN
            return (n == INT_MIN) ? x * myPow(x, INT_MAX) : myPow(x, -n);
        }
        
        // The fast powering logic
        double half = myPow(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }
    }
};