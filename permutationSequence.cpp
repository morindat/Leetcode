#include <vector>
#include <string>
using namespace std;

/**
 * Problem 178
 * Problem 15/45 of June 2026
 * Permutation Sequence: HARD
 * Date: 9/06/26
 * Time Complexity: O(n * n)
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        // precompute factorials
        vector<int> factorial (n + 1, 1);
        for (int i = 2; i <= n; i++) {
            factorial[i] = factorial[i - 1] * i;
        }

        // list of available numbers
        vector<int> nums;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }

        // convert k to 0-indexed
        k--;

        string result = "";

        for (int i = n; i > 0; i--) {
            int index = k / factorial[i - 1];
            result += to_string(nums[index]);
            nums.erase(nums.begin() + index);
            k %= factorial[i - 1];
        }

        return result;
    }
};