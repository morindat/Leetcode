#include <vector>
using namespace std;

/**
 * Problem 168
 * Problem 5/45 of June 2026
 * Beautiful Array: MEDIUM
 * Date: 2/06/26
 * Time Complexity: O(n)
*/

class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> result = {1};

        while (result.size() < n) {
            vector<int> temp;

            for (int x : result) {
                if (2*x - 1 <= n) temp.push_back(2*x - 1);
            }

            for (int x : result) {
                if (2*x <= n) temp.push_back(2*x);
            }

            result = temp;
        }

        return result;
    }

    vector<int> beautifulArrayRecursively(int n) {
        if (n == 1) return {1};

        vector<int> left = beautifulArrayRecursively((n + 1) / 2);
        vector<int> right = beautifulArrayRecursively(n / 2);

        vector<int> result;

        for (int x : left) {
            result.push_back(2*x - 1);
        }

        for (int x : right) {
            result.push_back(2*x);
        }

        return result;
    }
};