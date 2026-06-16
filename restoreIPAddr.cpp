#include <vector>
#include <string>
using namespace std;

/**
 * Problem 188
 * Problem 25/45 of June 2026
 * Restore IP Addresses: MEDIUM
 * Date: 16/06/26
 * Time Complexity: O(1)
*/

class Solution {
private:
    bool isValidOctet(const string& s) {
        if (s.empty() || s.length() > 3) return false;
        
        // Check for leading zero
        if (s.length() > 1 && s[0] == '0') return false;
        
        // Check range 0-255
        int num = stoi(s);
        return num >= 0 && num <= 255;
    }
    
    void backtrack(const string& s, int start, vector<string>& parts, vector<string>& result) {
        // Base case: found all 4 parts
        if (parts.size() == 4) {
            if (start == s.length()) {
                result.push_back(parts[0] + "." + parts[1] + "." + parts[2] + "." + parts[3]);
            }
            return;
        }
        
        // Optimization: if remaining characters can't form valid parts
        int remaining = s.length() - start;
        int needed = 4 - parts.size();
        if (remaining < needed || remaining > needed * 3) {
            return;
        }
        
        // Try taking 1, 2, or 3 digits
        for (int len = 1; len <= 3 && start + len <= s.length(); len++) {
            string octet = s.substr(start, len);
            
            if (isValidOctet(octet)) {
                parts.push_back(octet);
                backtrack(s, start + len, parts, result);
                parts.pop_back();
            }
        }
    }
    
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> parts;
        
        // Early pruning: length must be between 4 and 12
        if (s.length() < 4 || s.length() > 12) return result;
        
        backtrack(s, 0, parts, result);
        return result;
    }
};

// Optimized with Pruning
class Solution {
private:
    bool isValid(string& s, int start, int len) {
        if (len > 3 || start + len > s.length()) return false;
        
        // Check for leading zero
        if (s[start] == '0' && len > 1) return false;
        
        // Check range
        int num = stoi(s.substr(start, len));
        return num <= 255;
    }
    
    void backtrack(string& s, int start, vector<string>& parts, vector<string>& result) {
        if (parts.size() == 4) {
            if (start == s.length()) {
                result.push_back(parts[0] + "." + parts[1] + "." + parts[2] + "." + parts[3]);
            }
            return;
        }
        
        // Pruning: remaining length must be enough for remaining parts
        int remaining = s.length() - start;
        int need = 4 - parts.size();
        if (remaining < need || remaining > need * 3) return;
        
        for (int len = 1; len <= 3 && start + len <= s.length(); len++) {
            if (isValid(s, start, len)) {
                parts.push_back(s.substr(start, len));
                backtrack(s, start + len, parts, result);
                parts.pop_back();
            }
        }
    }
    
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> parts;
        
        // Impossible cases
        if (s.length() < 4 || s.length() > 12) return result;
        
        backtrack(s, 0, parts, result);
        return result;
    }
};