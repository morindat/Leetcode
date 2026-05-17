# include <unordered_map>
# include <unordered_set>
# include <vector>
# include <queue>
# include <algorithm>
using namespace std;

// Problem 36
// Problem 5 of Feb
// Design Twitter: MEDIUM
// Date: 09/02/26

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Count frequencies
        vector<int> freq(26, 0);
        for (char task : tasks) {
            freq[task - 'A']++;
        }
        
        // Sort frequencies
        sort(freq.begin(), freq.end(), greater<int>());
        
        // Find maximum frequency
        int maxFreq = freq[0];
        
        // Count how many tasks have max frequency
        int maxCount = 0;
        for (int f : freq) {
            if (f == maxFreq) {
                maxCount++;
            }
        }
        
        // Calculate minimum intervals
        // Case 1: Enough tasks to fill all slots without idle
        // Case 2: Need idle time between most frequent tasks
        int intervals = (maxFreq - 1) * (n + 1) + maxCount;
        
        // Return the maximum between calculated intervals and total tasks
        return max(intervals, (int)tasks.size());
    }
};


class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        std::unordered_map<char, int> freq;
        for (char task : tasks) freq[task]++;

        // Max-heap of frequencies
        std::priority_queue<int> pq;
        for (const auto& [task, count] : freq) {
            pq.push(count);
        }

        int time = 0;
        while (!pq.empty()) {
            std::vector<int> nextCycle;
            int slots = n + 1; // Process up to n+1 tasks per cycle

            while (slots > 0 && !pq.empty()) {
                int count = pq.top() - 1;
                pq.pop();
                if (count > 0) nextCycle.push_back(count);
                slots--;
                time++;
            }

            // Push remaining tasks back to heap
            for (int count : nextCycle) {
                pq.push(count);
            }

            // If heap isn't empty, add idle time for remaining slots
            if (!pq.empty()) {
                time += slots; // Idle time
            }
        }
        return time;
    }
};