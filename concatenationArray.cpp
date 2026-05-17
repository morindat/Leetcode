# include <vector>
using namespace std;

// Problem 104
// Problem 13 of April
// Concate Arrays: EASY
// Date: 09/04/26
// Complexity: O(n)

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> nums2 (nums);
        for (auto& num : nums){
            nums2.push_back(num);
        }

        return nums2;
    }
};