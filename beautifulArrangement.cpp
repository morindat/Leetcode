#include <vector>
using namespace std;

/**
 * Problem 179
 * Problem 16/45 of June 2026
 * Beautiful Arrangement: MEDIUM
 * Date: 10/06/26
 * Time Complexity: O(k)
*/

class Solution {
private:
    void backtrack(int n, int pos, vector<bool>& used, int& count) {
        // base case, we have used/filled every position
        if (pos > n) {
            count++;
            return;
        }

        for (int num = 1; num <= n; num++) {
            if (!used[num] && (num % pos == 0 || pos % num == 0)) {
                used[num] = true;
                backtrack(n, pos + 1, used, count);

                // backtrack
                used[num] = false;
            }
        }
    }

public:
    int countArrangement(int n) {
        int count = 0;
        vector<bool> used (n + 1, false);
        backtrack(n, 1, used, count);
        return count;
    }
};