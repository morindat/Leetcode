#include <vector>
using namespace std;

/**
 * Problem 191
 * Problem 28/45 of June 2026
 * Pascal Triangle: EASY
 * Date: 28/06/26
 * Time Complexity: O(n^2)
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;

        for (int i = 0; i < numRows; i++) {
            // Each row starts and ends with one
            // And is of size i + 1
            vector<int> row (i + 1, 1);

            // Each of the middle elements is the sum of the number above
            for (int j = 1; j < i; j++) {
                row[j] = triangle[i-1][j-1] + triangle[i-1][j];
            }

            triangle.push_back(row);
        }

        return triangle;
    }
};