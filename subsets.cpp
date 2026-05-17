# include <vector>
# include <iostream>
using namespace std;

// Problem 76
// Problem 22 of March
// Subsets: MEDIUM
// Date: 17/03/26
// Complexity: O(n * 2^n)


void generateSubsets(vector<int>& nums, int index, vector<int>& current, 
                     vector<vector<int>>& subsets) {
    // Add the current subset to result
    subsets.push_back(current);
    
    // Generate all subsets starting from current index
    for (int i = index; i < nums.size(); i++) {
        // Include nums[i] in the current subset
        current.push_back(nums[i]);
        
        // Recursively generate subsets with this element included
        generateSubsets(nums, i + 1, current, subsets);
        
        // Backtrack: remove nums[i] from current subset
        current.pop_back();
    }
}

vector<vector<int>> findSubsetsRecursive(vector<int>& nums) {
    vector<vector<int>> subsets;
    vector<int> current;
    generateSubsets(nums, 0, current, subsets);
    return subsets;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> subsets = findSubsetsRecursive(nums);
    
    cout << "All subsets (recursive method):" << endl;
    for (auto& subset : subsets) {
        cout << "[";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i < subset.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}