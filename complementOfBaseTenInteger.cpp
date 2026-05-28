# include <iostream>
using namespace std;

/**
 * Problem 158
 * Problem 45/45 of May 2026
 * Complement Of Base 10 Integer: EASY
 * Date: 28/05/26
 * Time Complexity: O(log5 n)
*/


class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        
        // Find the number of bits needed
        int mask = 0;
        int temp = n;
        
        while (temp > 0) {
            mask = (mask << 1) | 1;  // Build mask of all 1's with same length
            temp >>= 1;
        }
        
        // XOR flips the bits
        return n ^ mask;
    }
};