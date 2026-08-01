#include <vector>
#include <iostream>
using namespace std;


/*
 * Welcome Back Brother
 * First Problem after a long vacation
 * Problem 193
 * Range Sum Query - Immutable: EASY
 * Time: 2026-08-01
 * Time Complexity: 0(1)
 */

class NumArray {
private:
    vector<int> arr;
    vector<int> prefix;

public:
    NumArray(vector<int>& nums) {
        arr = nums;
        prefix.resize(nums.size() + 1, 0);

        for (int i = 0; i < nums.size(); i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};


int main() {
    vector<int> arr = {-2, 0, 3, -5, 2, -1};
    NumArray numArray(arr);

    vector<pair<int, int>> testCase = {
        {0, 2},
        {2, 5},
        {0, 5},
        {1, 4}
    };

    cout << "Testing Range Sum" << endl;
    
    for (auto & t : testCase) {
        int left = t.first;
        int right = t.second;
        
        cout << "sumRange(" << left << ", " << right << ") = " 
             << numArray.sumRange(left, right) << endl;
    } 

    return 0;
}


