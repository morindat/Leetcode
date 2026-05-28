# include <iostream>
using namespace std;

/**
 * Problem 157
 * Problem 44/45 of May 2026
 * Add Digits: EASY
 * Date: 28/05/26
 * Time Complexity: O(log5 n)
*/

class Solution {
public:
    int addDigits(int num) {
        if (num < 10) return num;
        
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        
        return addDigits(sum);
    }
};

class Solution2 {
public:
    int addDigits(int num) {
        if (num == 0) return 0;
        return 1 + (num - 1) % 9;
    }
};