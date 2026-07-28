#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// Problem 45
// Problem 15 of Feb
// IPO: HARD
// Date: 19/02/26

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        
        // 1. COMBINE & SORT
        // Store pairs of {capital, profit}.
        // Default pair sorting sorts by the first element (capital) ascending.
        // Intuition: This allows us to efficiently find all projects we can afford
        // as our capital (w) increases, using a simple pointer.
        vector<pair<int, int>> projects;
        projects.reserve(n);
        for (int i = 0; i < n; ++i) {
            projects.push_back({capital[i], profits[i]});
        }
        
        sort(projects.begin(), projects.end());
        
        // 2. INITIALIZE MAX-HEAP
        // C++ priority_queue is a Max-Heap by default.
        // It will store the profits of all currently affordable projects.
        priority_queue<int> maxHeap;
        
        int i = 0; // Pointer for the sorted projects list
        
        // 3. LOOP K TIMES
        // We want to complete at most k projects
        for (int step = 0; step < k; ++step) {
            // 4. INJECT AFFORDABLE PROJECTS INTO HEAP
            // Move the pointer 'i' forward. Any project with capital <= w is now affordable.
            // Push its profit into the heap.
            while (i < n && projects[i].first <= w) {
                maxHeap.push(projects[i].second);
                i++;
            }
            
            // 5. CHECK AVAILABILITY
            // If the heap is empty, it means we cannot afford any of the remaining projects.
            // We must stop early.
            if (maxHeap.empty()) {
                break;
            }
            
            // 6. SELECT BEST PROJECT
            // top() gives the largest profit. pop() removes it.
            // Add it to our current capital w.
            w += maxHeap.top();
            maxHeap.pop();
        }
        
        return w;
    }
};
