# include <vector>
using namespace std;

// Problem 74
// Problem 20 of March
// Redundant Connection: MEDIUM
// Date: 14/03/26
// Complexity: O(m*n)

class Solution {
public:
    int m, n;
    
    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& vis) {
        vis[r][c] = true;
        
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        
        for(auto &d : dirs) {
            int nr = r + d[0];
            int nc = c + d[1];
            
            if(nr < 0 || nc < 0 || nr >= m || nc >= n)
                continue;
            
            if(vis[nr][nc])
                continue;
            
            if(heights[nr][nc] < heights[r][c])
                continue;
                
            dfs(heights, nr, nc, vis);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        m = heights.size();
        n = heights[0].size();
        
        vector<vector<bool>> pac(m, vector<bool>(n,false));
        vector<vector<bool>> atl(m, vector<bool>(n,false));
        
        for(int i=0;i<m;i++) {
            dfs(heights, i, 0, pac);      // pacific left
            dfs(heights, i, n-1, atl);    // atlantic right
        }
        
        for(int j=0;j<n;j++) {
            dfs(heights, 0, j, pac);      // pacific top
            dfs(heights, m-1, j, atl);    // atlantic bottom
        }
        
        vector<vector<int>> ans;
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(pac[i][j] && atl[i][j])
                    ans.push_back({i,j});
            }
        }
        
        return ans;
    }
};