#include <vector>
using namespace std;

/**
 * Problem 175
 * Problem 12/45 of June 2026
 * Sum of All Subset XOR Totals: EASY
 * Date: 8/06/26
 * Time Complexity: O(2^n), O(n)
*/

class Solution {
private:
    int total = 0;
    
    void backtrack(vector<int>& nums, int index, int currentSum) {
        if (index == nums.size()) {
            total += currentSum;
            return;
        }

        // skip current elemento
        backtrack(nums, index + 1, currentSum);

        // xor the current element
        backtrack(nums, index + 1, currentSum ^ nums[index]);
    }

public:
    int subsetXORSum(vector<int>& nums) {
        backtrack(nums, 0, 0);
        return total;
    }
};

class Solution {
public:
    // mathematical O(n)
    int subsetXORSum(vector<int>& nums) {
        int OR = 0;
        for (int num : nums) {
            OR |= num;
        }
        return OR * (1 << (nums.size() - 1));
    }
};