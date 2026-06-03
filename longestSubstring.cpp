#include <vector>
#include <string>
using namespace std;

/**
 * Problem 167
 * Problem 4/45 of June 2026
 * Longest Substring with At Least K Repeating Characters: MEDIUM
 * Date: 2/06/26
 * Time Complexity: O(n log n) Divide and Conquer, O(n) Sliding Window
*/


class Solution {
private:
    int substring(string s,int k, int start, int end) {
        if (end - start < k) return 0;

        // Freq of chars
        vector<int> count(26, 0);

        for (int i = start; i < end; i++) {
            count[s[i] - 'a']++;
        }

        // Find the first invalid character
        for (int i = start; i < end; i++) {
            // Split at this charecter
            if (count[s[i] - 'a'] < k) {
                int left = substring(s, k, start, i);
                int right = substring(s, k, i + 1, end);
                return max(left, right);
            }
        }

        // All characters appear at least k times
        return end - start;
    }

public:
    int longestSubstring(string s, int k) {
        return substring(s, k, 0, s.length());
    }
};

class Solution {
public:
    int longestSubstring(string s, int k) {
        int maxLen = 0;
        
        // Try for each possible number of unique characters (1 to 26)
        for (int uniqueTarget = 1; uniqueTarget <= 26; uniqueTarget++) {
            vector<int> count(26, 0);
            int left = 0, unique = 0, atLeastK = 0;
            
            for (int right = 0; right < s.length(); right++) {
                // Add right character
                int idx = s[right] - 'a';
                count[idx]++;
                if (count[idx] == 1) unique++;
                if (count[idx] == k) atLeastK++;
                
                // Shrink if too many unique characters
                while (unique > uniqueTarget) {
                    int leftIdx = s[left] - 'a';
                    count[leftIdx]--;
                    if (count[leftIdx] == 0) unique--;
                    if (count[leftIdx] == k - 1) atLeastK--;
                    left++;
                }
                
                // If all characters in window meet threshold
                if (unique == atLeastK) {
                    maxLen = max(maxLen, right - left + 1);
                }
            }
        }
        
        return maxLen;
    }
};