# include <vector>
# include <queue>
# include <string>
# include <unordered_set>
using namespace std;

// Problem 79
// Problem 25 of March
// Word Ladder: HARD
// Date: 20/03/26
// Complexity: O(N × L × 26)
// N words, L positions per word, 26 transformations

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // store the words in a set for fast lookup
        unordered_set<string> st(wordList.begin(), wordList.end());

        // We can go ahead and check if the end word is in the the set
        // if not just return 0 immediately
        if (!st.count(endWord)) return 0;

        // otherwise we do a bfs
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()){
            auto [word, level] = q.front();
            q.pop();

            if (word == endWord) return level;

            // otherwise we transform the word letter by letter
            for (int i = 0; i < word.size(); i++) {
                string temp = word;

                for (char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;

                    // if the transformed word is in the set
                    // mark it visited by removing it
                    // push the word formed to the queue
                    if (st.count(temp)){
                        q.push({temp, level + 1});
                        st.erase(temp);
                    }
                }
            }
        }

        return 0;
    }
};