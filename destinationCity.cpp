#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

// Problem 60
// Problem 6 of March
// Island Perimeter: EASY
// Date: 05/03/26

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        // for each city that is not destinatination
        // it appears both in from - and to
        // considering each input as from -- to
        // so put every city in a set
        // the one that does not appear in from set
        // is the destination city

        unordered_set<string> from;

        // push all the from cities to set
        for (auto& p : paths){
            from.insert(p[0]);
        }
        
        // seach the from set, for any to city that did not 
        // appear in the set
        for (auto& p : paths){
            if (!from.count(p[1])){
                return p[1];
            }
        }

        return "";
    }
};