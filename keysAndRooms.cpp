# include <vector>
# include <queue>
using namespace std;

// Problem 86
// Problem 32 of March
// Keys and Rooms: MEDIUM
// Date: 29/03/26
// Complexity: O(V + E)

class Solution {
public:
    
    // DFS function to visit rooms
    void dfs(int room, vector<vector<int>>& rooms, vector<bool>& visited) {
        
        // mark current room as visited
        visited[room] = true;
        
        // iterate over all keys in this room
        for (int key : rooms[room]) {
            
            // if the room corresponding to this key is not visited
            if (!visited[key]) {
                
                // visit that room using DFS
                dfs(key, rooms, visited);
            }
        }
    }
    
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n = rooms.size();
        
        // visited array to track visited rooms
        vector<bool> visited(n, false);
        
        // start DFS from room 0
        dfs(0, rooms, visited);
        
        // check if all rooms were visited
        for (int i = 0; i < n; i++) {
            
            // if any room not visited, return false
            if (!visited[i]) {
                return false;
            }
        }
        
        // all rooms visited
        return true;
    }
};

// BFS
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n = rooms.size();
        vector<bool> visited(n, false);
        queue<int> q;
        
        // start from room 0
        q.push(0);
        visited[0] = true;
        
        while (!q.empty()) {
            int room = q.front();
            q.pop();
            
            // check all keys in current room
            for (int key : rooms[room]) {
                
                // if not visited, visit it
                if (!visited[key]) {
                    visited[key] = true;
                    q.push(key);
                }
            }
        }
        
        // check if all rooms visited
        for (bool v : visited) {
            if (!v) return false;
        }
        
        return true;
    }
};