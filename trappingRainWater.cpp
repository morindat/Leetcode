# include <vector>
# include <queue>
using namespace std;

// Problem 94
// Problem 2 of April
// Trapping Rain Water: HARD
// Date: 02/04/26
// Complexity: O(n)

class Solution {
public: 
    int trap(vector<int>& height) {
        // set two pointers
        // one at the begining of the array
        // the other at the end
        int left = 0;
        int right = height.size()-1;

        // keep track of the highest buildings seen so far
        int leftMax = 0;
        int rightMax = 0;

        int total = 0;
        /*
        * CORE IDEA:
            -> Water trapped at index i = min(leftMax, rightMax) - heights[i];
            -> All we have to do is check which side is limiting
                -> If leftHeight < rightHeight then leftHeight is 
                -> Otherwise the right height is
        */

        while (left < right) {
            // if the left height is smaller, water depends on left max
            if (height[left] < height[right]){
                // update leftMax if the water level at height[left] is >
                if (height[left] >= leftMax){
                    leftMax = height[left];
                } else {
                    // we found a valley so add water to total
                    total += leftMax - height[left];
                }

                // move the ptr
                left++;
            } else {
                if (height[right] >= rightMax){
                    rightMax = height[right];
                } else {
                    total += rightMax - height[right];
                }

                right--;
            }
        }

        return total;
    }   
};