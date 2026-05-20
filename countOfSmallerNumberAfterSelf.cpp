# include <vector>
# include <iostream>
using namespace std;

/**
 * Problem 127
 * Problem 14/45 of May 2026
 * Count Of Smaller Numbers After Self: HARD
 * Date: 20/05/26
 * Time Complexity: O(n log n);
 */


class Solution {
private:
    vector<int> indices; // store the original indices
    vector<int> result;

    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);

        // count smaller elementos
        int j = mid + 1;

        for (int i = left; i <= mid; i++) {
            while (j <= right && nums[indices[j]] < nums[indices[i]]) {
                j++;
            }

            result[indices[i]] += j - (mid + 1);
        }

        // merge step
        vector<int> temp;
        int i = left, k = mid + 1;

        while (i <= mid && k <= right) {
            if (nums[indices[i]] <= nums[indices[k]]) {
                temp.push_back(indices[i++]);
            } else {
                temp.push_back(indices[k++]);
            }
        }

        while (i <= mid) temp.push_back(indices[i++]);
        while (k <= right) temp.push_back(indices[k++]);

        for (int i = left; i <= right; i++) {
            indices[i] = temp[i - left];
        }
    }


public:
    vector<int> countSmaller(vector<int>& nums) {
        // bad O(n^2) solution

        // vector<int> res(nums.size());

        // for (int i = 0; i < nums.size(); i++) {
        //     int count = 0;
        //     for (int j = i + 1; j < nums.size(); j++) {
        //         if (nums[j] < nums[i]) {
        //             count++;
        //         }
        //     }
        //     res[i] = count;
        // }
        
        // return res;

        int n = nums.size();
        result.assign(n, 0);
        indices.resize(n);
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }
        
        mergeSort(nums, 0, n - 1);
        return result;

    }
};

int main() {
    Solution sol;

    vector<int> nums = {5, 2, 6, 1};
    vector<int> res = sol.countSmaller(nums);

    for (int num : res) {
        cout << num << " ";
    }

    cout << "\n";
}