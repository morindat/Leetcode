# include <queue>
# include <vector>
using namespace std;

// Problem 34
// Problem 3 of Feb
// Construct Target Array: HARD
// Date: 04/02/26

class Solution {
public:
    bool isPossible(vector<int>& target) {
        // Edge case: single element
        if (target.size() == 1) {
            return target[0] == 1;
        }
        
        // Step 1: Build max heap and calculate total sum
        priority_queue<int> maxHeap;
        long long total = 0;
        
        for (int num : target) {
            maxHeap.push(num);
            total += num;
        }
        
        // Step 2: Work backwards until we reach all 1s
        while (maxHeap.top() != 1) {
            int largest = maxHeap.top();
            maxHeap.pop();
            
            long long rest = total - largest;  // sum of OTHER elements
            
            // Base case: if rest is 1, we can always reach [1,1,1...]
            if (rest == 1) {
                return true;
            }
            
            // Invalid cases
            if (rest >= largest || rest == 0) {
                return false;
            }
            
            // Calculate previous value using modulo (optimization)
            int prev = largest % rest;
            
            // If prev becomes 0, it's impossible
            if (prev == 0) {
                return false;
            }
            
            // Update total and push previous value back to heap
            total = rest + prev;
            maxHeap.push(prev);
        }
        
        // If we exit the loop, maxHeap.top() == 1, meaning all elements are 1
        return true;
    }
};

/*

Walkthrough Example: target = [9, 3, 5]

Initial: maxHeap = [9, 5, 3], total = 17

Iteration 1:
  largest = 9, rest = 17 - 9 = 8
  prev = 9 % 8 = 1
  maxHeap = [5, 3, 1], total = 8 + 1 = 9

Iteration 2:
  largest = 5, rest = 9 - 5 = 4
  prev = 5 % 4 = 1
  maxHeap = [3, 1, 1], total = 4 + 1 = 5

Iteration 3:
  largest = 3, rest = 5 - 3 = 2
  prev = 3 % 2 = 1
  maxHeap = [1, 1, 1], total = 2 + 1 = 3

Now maxHeap.top() == 1, exit loop
Return true ✓

*/