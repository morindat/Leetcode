# include <vector>
# include<algorithm>
# include <queue>
using namespace std;

// Problem 44
// Problem 14 of Feb
// Smallest Range Covering Elements from K Lists: HARD
// Date: 18/02/26
// Time Complexity: O(n log k) n is the total number of elements across all lists,
// k is the size of the vector (number of sublists)


class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // global max

        int current_max = INT_MIN;
        // min heap to store the first elements of each list
        priority_queue<pair<int, pair<int, int>>, 
        vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>> pq;

        // a regular pattern these days
        // push in the first element of each subvec
        // update current max to the max of the 1 elements of each subvec
        for (int i = 0; i < nums.size(); i++){
            pq.push({nums[i][0], {i, 0}});
            if (nums[i][0] > current_max) current_max = nums[i][0];
        }

        int start = 0;
        int end = 0;
        int best_range = INT_MAX;

        while (!pq.empty()){
            auto top = pq.top();
            pq.pop();
            
            int current_min = top.first;
            int row = top.second.first;
            int col = top.second.second;

            int current_range = current_max - current_min;
            if (current_range < best_range){
                start = current_min;
                end = current_max;
                best_range = current_range;
            }
            
            // push the next elements of each suubvec to the pq
            if (col + 1 < nums[row].size()){
                int next_val = nums[row][col + 1];

                current_max = max(current_max, next_val);
                pq.push({next_val, {row, col + 1}});
            } else {
                break;
            }
        }
        
        return {start, end};
    }
};