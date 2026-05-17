#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

// Problem 37
// Problem 6 of Feb
// Task Scheduler: MEDIUM
// Date: 10/02/26

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) return tasks.size();
        
        // Count frequency of each task
        unordered_map<char, int> freq;
        for (char task : tasks) {
            freq[task]++;
        }
        
        // Push frequencies to max heap (priority queue)
        priority_queue<int> maxHeap;
        for (auto& pair : freq) {
            maxHeap.push(pair.second);
        }
        
        int time = 0;
        queue<pair<int, int>> cooldownQueue; // {remainingCount, availableTime}
        
        while (!maxHeap.empty() || !cooldownQueue.empty()) {
            time++;
            
            // Check if a task is ready from cooldown
            if (!cooldownQueue.empty() && cooldownQueue.front().second <= time) {
                maxHeap.push(cooldownQueue.front().first);
                cooldownQueue.pop();
            }
            
            // Execute a task if available
            if (!maxHeap.empty()) {
                int count = maxHeap.top();
                maxHeap.pop();
                count--;
                
                if (count > 0) {
                    // Put task back in cooldown
                    cooldownQueue.push({count, time + n + 1});
                }
            }
        }
        
        return time;
    }
};