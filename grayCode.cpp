#include <vector>
#include <string>
using namespace std;

/**
 * Problem 184
 * Problem 21/45 of June 2026
 * Gray Code: MEDIUM
 * Date: 14/06/26
 * Time Complexity: O(2^n)
*/

class Solution {
private:
    void generateGray(int n, vector<int>& res) {
        if (n == 0) {
            res.push_back(0);
            return;
        }

        generateGray(n-1, res);

        // add reverse with 1 at front
        int size = res.size();
        for (int i = size - 1; i >= 0; i--) {
            res.push_back(res[i] | (1 << (n-1)));
        }
    }

public:
    vector<int> grayCode(int n) {
        vector<int> res;

        generateGray(n, res);

        return res;
    }
};

class GrayCode {
public:
    // Formula method - most efficient
    vector<int> grayCodeFormula(int n) {
        vector<int> result;
        int total = 1 << n;  // 2^n
        
        for (int i = 0; i < total; i++) {
            result.push_back(i ^ (i >> 1));
        }
        
        return result;
    }
};