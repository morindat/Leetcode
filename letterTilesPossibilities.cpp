#include <vector>
#include <string>
using namespace std;

/**
 * Problem 182
 * Problem 19/45 of June 2026
 * Letter Tile Possibilities: MEDIUM
 * Date: 13/06/26
 * Time Complexity: O(k!)
*/

class Solution {
public:
    int numTilePossibilities(string tiles) {
        vector<int> freq(26, 0);
        for (char c : tiles) {
            freq[c - 'A']++;
        }
        
        return backtrack(freq);
    }
    
private:
    int backtrack(vector<int>& freq) {
        int count = 0;
        
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                // Use this letter
                freq[i]--;
                count += 1;  // Count the sequence we just formed
                count += backtrack(freq);  // Count longer sequences
                
                // Backtrack
                freq[i]++;
            }
        }
        
        return count;
    }
};