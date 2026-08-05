#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 * Problem 200
 * Longest Unequal Adjacent Groups Subsequence I: EASY 
 * Time: 2026-08-04
 * Complexity: 0(n)
 */ 

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;

        ans.push_back(words[0]);
        int last_group = groups[0];

        for (int i = 1; i < words.size(); i++) {
            if (groups[i] != last_group) {
                ans.push_back(words[i]);
                last_group = groups[i];
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<string> words1 = {"e", "a", "b"};
    vector<int> groups1 = {0, 0, 1};
    vector<string> result1 = sol.getLongestSubsequence(words1, groups1);
    
    cout << "Test 1: ";
    for (const string& w : result1) {
        cout << w << " ";
    }
    cout << endl;
    
    // Test Case 2
    vector<string> words2 = {"a", "b", "c", "d"};
    vector<int> groups2 = {1, 0, 1, 0};
    vector<string> result2 = sol.getLongestSubsequence(words2, groups2);
    
    cout << "Test 2: ";
    for (const string& w : result2) {
        cout << w << " ";
    }
    cout << endl;
    
    return 0;
}
