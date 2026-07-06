# include <vector>
# include<algorithm>
# include <queue>
using namespace std;

// Problem 39
// Problem 9 of Feb
// Car Pooling: MEDIUM
// Date: 15/02/26
// I have slacked so much this feb
// Was sick in the past 3 days but I was not dead so reason why I ain't solved any qn
// Lol, only 9/15 possible qns solved this month so far, gotta catch up ngl

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // sort by the starting pstn

        sort(trips.begin(), trips.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });

        // min heap for passengers number and end location
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        int currentPassengers = 0;

        // Now the real work
        
        for (auto &t: trips){
            int passengers = t[0], start = t[1], end = t[2];

            // remove completed trips
            while(!pq.empty() && pq.top().first <= start){
                // so that is, while the queue is not empty and the ending pstn is less or equal to some starting position
                // then remove the passengers of that position
                // soooo.....
                currentPassengers -= pq.top().second;
                pq.pop();
            }

            // otherwise add new trips and increment the passengers
            pq.push({end, passengers});
            currentPassengers += passengers;

            // exit?
            if (currentPassengers > capacity) return false;
        }

        // else return true
        return true;
    }
};
