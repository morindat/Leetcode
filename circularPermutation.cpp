#include <vector>
#include <string>
using namespace std;

/**
 * Problem 183
 * Problem 20/45 of June 2026
 * Circular Permutation: MEDIUM
 * Date: 14/06/26
 * Time Complexity: O(2^n)
*/

class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> result;
        int total = 1 << n;  // 2^n numbers
        
        // Generate Gray code sequence using the formula
        for (int i = 0; i < total; i++) {
            int grayCode = i ^ (i >> 1);
            result.push_back(start ^ grayCode);  // XOR with start to rotate
        }
        
        return result;
    }
};