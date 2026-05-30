# include <iostream>
using namespace std;

/**
 * Problem 160
 * Problem 47/45 of May 2026
 * Number of Steps to Reduce a Number to Zero: EASY
 * Date: 30/05/26
 * Time Complexity: O(log n)
*/

class Solution {
private:
    void countSteps(int num, int& count) {
        if (num <= 0) return;

        if (num % 2 == 0) {
            num /= 2;
            count++;
        } else {
            num -= 1;
            count++;
        }

        countSteps(num, count);
    }

public:
    int numberOfSteps(int num) {

        int count = 0;

        countSteps(num, count);

        return count;
    }
};