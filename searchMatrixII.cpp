#include <vector>
using namespace std;

/**
 * Problem 166
 * Problem 3/45 of June 2026
 * Search a 2D Matrix II: MEDIUM
 * Date: 1/06/26
 * Time Complexity: O(m + n)
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int col = matrix[0].size() - 1;

        while (row < matrix.size() && col >= 0) {
            // if the current element is the target, simply return true
            if (matrix[row][col] == target) {
                return true;
            }
            
            // if it is >, eliminate the column
            else if (matrix[row][col] > target) {
                col--;
            } else {
                // eliminate the row otherwise
                row++;
            }
        }

        return false;
    }
};