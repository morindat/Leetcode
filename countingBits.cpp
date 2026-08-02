#include <vector>
#include <iostream>
using namespace std;

/*
 * Problem 195
 * Count Bits: EASY
 * Time: 2026-08-02
 * Time Complexity: 0(n) 
 * TC: O(n log n) --the naive way
 */ 

/*
 * So basically we are given an int value say 2
 * And all we have to do is output the number of 1s (set bits) that are in that number
 * For instance for 2, output : [0, 1, 1]
 * Why? bcoz in range(2) 0, 1, 2, in each number from 0 to 2 we the number of 1s in its binary representation
 */

class Solution {
private:

public:
    // We can easily solve this using the Brian Kernighan's Algorithm
    // Which is an efficient bit manipulation method used to count the 
    // Number of set bits (1s) in the binary representation of an integer
    // And it works by continuously applying n = n & n - 1
    // The number is eventually reduced to 0

    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            // i & i - 1, removes the lowest set bit
            // +1 for the removed bit
            dp[i] = dp[i & (i - 1)] + 1;
        }

        return dp;
    }

    // Here is the naive way of doing this 
    // The classis converting and counting 

    vector<int> countBitsNaive(int n) {
        vector<int> ans;

        for (int i = 0; i <= n; i++) {
            int count = 0;
            int num = i;

            while (num > 0) {
                count += num & 1;
                num >>= 1;
            }

            ans.push_back(count);
        }

        return ans;
    }
};


int main() {
    Solution s;
    int n = 4;

    vector<int> res = s.countBitsNaive(n);
    for (int i = 0; i <= n; i++) {
        std::cout << res[i] << " ";
    }
    
    std::cout << "\n";
    
    return 0; 
}


