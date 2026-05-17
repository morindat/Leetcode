# include <vector>
# include<algorithm>
# include <queue>
using namespace std;

// Problem 42
// Problem 12 of Feb
// Kth Smallest Element In a Sorted Matrix: MEDIUM
// Date: 16/02/26
// Time Complexity: k log n (n is the size of matrix)
// Space Complexity: O(n) for the heap

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // get size of the matrix
        int n = matrix.size();
        
        // we need to store the first elements of each row, so element, row, col
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        
        // push the first element of each row (element, row, col)
        for (int i = 0; i < n; i++){
            pq.push({matrix[i][0], i, 0});
        }

        // pop the smallest element one at a time until k becomes 1
        while (--k){
            auto[val, r, c] = pq.top(); pq.pop();
            // if we aint at the end of the row, then add the col element at the pq
            if (c + 1 < n){
                pq.push({matrix[r][c + 1], r, c + 1});
            }
        }

        // return the element
        return get<0>(pq.top());
    }   
};