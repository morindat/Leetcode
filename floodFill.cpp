# include <vector>
# include <queue>
# include <iostream>
using namespace std;

// Problem No. 1.
// Flood Fill: EASY
// Date: 01/01/26.

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // visited array for m * n matrix (image)
        // I need the dimensions of the image too, so get them as follows
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));

        // Queue (to store the row, col of the image)
        queue<pair<int, int>> q;

        // We need to know the original color so that we do not color a colored cell
        // If the original color is the same as the color then we stop the algorithm imediately, there is nothing to do

        int originalColor = image[sr][sc];
        if (originalColor == color) return image;

        // push starting cell to start the bfs traversal (classic step)
        // mark the starting cell as visited and color it too
        q.push({sr, sc});
        visited[sr][sc] = 1;
        image[sr][sc] = color;

        // We need to work with four directions so we need them
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while (!q.empty()){
            // Now pop the first element in the queue
            auto [r, c] = q.front();
            q.pop();

            // Loop for every neighbour of that cell in all 4 directions
            for (int k = 0; k < 4; k++){
                // new row and new col
                int nr = r + dr[k];
                int nc = c + dc[k];

                // So here we need a couple checks
                // 1. make sure nr and nc are within reach given the size of the image
                // 2. If we have not visited the new col and new row and they have og color then visit them
                // color them with color
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc] && image[nr][nc] == originalColor){
                    visited[nr][nc] = 1;
                    image[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }
        return image;
    }
};

// Helper function to print a 2D matrix
void printImage(const vector<vector<int>>& image) {
    for (const auto& row : image) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution sol;

    // Example image
    vector<vector<int>> image = {
        {1, 1, 0, 0},
        {1, 0, 0, 1},
        {0, 0, 1, 1},
        {0, 1, 1, 0}
    };

    int sr = 0, sc = 0; // starting cell
    int color = 2;       // new color

    cout << "Original image:" << endl;
    printImage(image);
    cout << endl;

    vector<vector<int>> result = sol.floodFill(image, sr, sc, color);

    cout << "Flood-filled image:" << endl;
    printImage(result);
    cout << endl;

    return 0;
}

// Better solution
// Color immidiately so you do not need the visited array
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        int originalColor = image[sr][sc];
        if (originalColor == color) return image;

        queue<pair<int,int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && image[nr][nc] == originalColor) {
                    image[nr][nc] = color;  // color immediately
                    q.push({nr, nc});
                }
            }
        }

        return image;
    }
};
