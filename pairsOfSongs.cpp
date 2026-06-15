#include <vector>
#include <unordered_map>
using namespace std;

/**
 * Problem 185
 * Problem 22/45 of June 2026
 * Pairs of Songs With Total Durations Divisible by 60: MEDIUM
 * Date: 15/06/26
 * Time Complexity: O(n)
*/


class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> count;
        int pairs = 0;
        
        for (int t : time) {
            int remainder = t % 60;
            int needed = (60 - remainder) % 60;
            
            pairs += count[needed];
            count[remainder]++;
        }
        
        return pairs;
    }
};

// O(60) Space complexity solution
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> remainderCount(60, 0);
        int pairs = 0;
        
        for (int duration : time) {
            int remainder = duration % 60;
            int complement = (60 - remainder) % 60;
            
            pairs += remainderCount[complement];
            remainderCount[remainder]++;
        }
        
        return pairs;
    }
};

// Backtracking solution -> O(n^2)
class Solution {
private:
    int count = 0;

    void backtrack(vector<int>& times, vector<int>& current, int start) {
        if (current.size() == 2) {
            if ((current[0] + current[1]) % 60 == 0){
                count++;
            }
            return;
        }

        for (int i = start; i < times.size(); i++) {
            current.push_back(times[i]);
            backtrack(times, current, i + 1);
            current.pop_back();
        }
    }

public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> current;
        backtrack(time, current, 0);
        return count;
    }
};

/**
time = [30,20,150,100,40]
Initialize: count[0..59] = 0, pairs = 0

t=30:
  remainder = 30
  needed = (60-30)%60 = 30
  pairs += count[30] = 0
  count[30]++ → count[30]=1

t=20:
  remainder = 20
  needed = (60-20)%60 = 40
  pairs += count[40] = 0
  count[20]++ → count[20]=1

t=150:
  remainder = 150%60 = 30 (since 120 + 30)
  needed = 30
  pairs += count[30] = 1 ← (30,150) found!
  count[30]++ → count[30]=2

t=100:
  remainder = 100%60 = 40
  needed = 20
  pairs += count[20] = 1 ← (20,100) found!
  count[40]++ → count[40]=1

t=40:
  remainder = 40
  needed = 20
  pairs += count[20] = 1 ← (20,40) found!
  count[40]++ → count[40]=2

Result: pairs = 3 
 */