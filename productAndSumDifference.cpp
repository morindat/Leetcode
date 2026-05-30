# include <iostream>
using namespace std;

/**
 * Problem 159
 * Problem 46/45 of May 2026
 * Subtract the Product and Sum of Digits of an Integer: EASY
 * Date: 30/05/26
 * Time Complexity: O(log n)
*/

class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1;
        int sum = 0;

        while (n > 0) {
            int digit = n % 10;
            sum += digit;
            product *= digit;
            n /= 10;
        }

        return product - sum;
    }
};

class Solution {
public:
    int subtractProductAndSum(int n) {
        return helper(n, 1, 0);
    }
    
private:
    int helper(int n, int product, int sum) {
        if (n == 0) return product - sum;
        int digit = n % 10;
        return helper(n / 10, product * digit, sum + digit);
    }
};