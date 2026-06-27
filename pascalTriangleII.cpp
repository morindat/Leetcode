#include <vector>
using namespace std;

/**
 * Problem 192
 * Problem 29/45 of June 2026
 * Pascal Triangle II: EASY
 * Date: 28/06/26
 * Time Complexity: O(n^2) 
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);

        for (int i = 1; i <= rowIndex; i++) {
            // update from right to right to avoid overwriting
            for (int j = i - 1; j > 0; j++) {
                row[j] = row[j] + row[j - 1];
            }
        }

        return row;
    }
};