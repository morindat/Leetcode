# include <vector>
# include<algorithm>
# include <queue>
using namespace std;

// Problem 41
// Problem 11 of Feb
// Furthest Building You Can Reach: MEDIUM
// Date: 16/02/26
// I still owe feb 5 fucking qns brev
// I cursed a lot on this qn, sorry

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // we will use a fucking max heap
        // took me forever just to understand the min heap solution and i still have not understood shit
        // bloody hell, yeah am crushing out, tf

        priority_queue<int> maxHeap;

        for (int i = 0; i < heights.size() - 1; i++){
            int diff = heights[i + 1] - heights[i];

            if (diff > 0){
                bricks -= diff;
                maxHeap.push(diff);
                
                // If we run out of bricks the fuck we do gang??
                if (bricks < 0){

                    // well, check if we have ladders or not
                    // we dont?
                    if (ladders == 0) return i;

                    // otherwise just use the fucking ladder
                    bricks += maxHeap.top();
                    maxHeap.pop();
                    ladders--;
                }
            }
        }

        // we made it to the end
        return heights.size() - 1;
    }
};