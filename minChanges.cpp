#include <vector>
#include <string>
using namespace std;

// Problem 63
// Problem 9 of March
// Minimum Changes To Make Alternating Binary String: EASY
// Date: 06/03/26
// So now I owe February just 2 qns
// Complexity: O(n)

class Solution {
public:
    int minOperations(string s) {
        int start0 = 0; // pattern: 010101
        int start1 = 0; // pattern: 101010

        for (int i = 0; i < s.size(); i++) {
            char expected0 = (i % 2 == 0) ? '0' : '1';
            char expected1 = (i % 2 == 0) ? '1' : '0';

            if (s[i] != expected0) start0++;
            if (s[i] != expected1) start1++;
        }

        return min(start0, start1);
    }
};