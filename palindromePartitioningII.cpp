#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

/*
 * Problem 219
 * Palindrome Partition: HARD 
 * Date: 01/10/2026
 * Complexity: O(n^2) 
 */

class Solution {
private:
  bool isPalindrome(string &s, int left, int right) {
    while (left < right) {
      if (s[left] != s[right])
        return false;
      left++;
      right--;
    }

    return true;
  }

public:
  int minCut(string s) {
    int n = s.size();

    vector<int> dp(n + 1, 0);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--) {
      int minCost = INT_MAX;
      for (int j = i; j < n; j++) {
        if (isPalindrome(s, i, j)) {
          int cost = 1 + dp[j + 1];
          minCost = min(minCost, cost);
        }
      }

      dp[i] = minCost;
    }

    return dp[0] - 1;
  }
};

int main() {
  Solution sol;
  string s = "aab";

  cout << "Min Cut: " << sol.minCut(s) << "\n";

  return 0;
}
