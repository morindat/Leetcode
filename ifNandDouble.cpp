# include <vector>
# include <unordered_set>
using namespace std;

// Problem 68
// Problem 14 of March
// Leaf Similar Trees
// Date: 07/03/26
// Complexity: O(n)

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        // push the elements into a set
        unordered_set<int> seen;
        
        // if set contains the double of that element
        // or if the element we are looking at is even and half of it is in the set
        // we found it
        
        for (int x : arr) {
            if (seen.count(2 * x) || (x % 2 == 0 && seen.count(x / 2))) {
                return true;
            }
            seen.insert(x);
        }

        return false;
    }
};