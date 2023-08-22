//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    // Function to find the number of islands.
void bfs(vector<vector<char>>& grid, vector<vector<int>>&visited,  int row, int col) {
    int n = grid.size();
    int m = grid[0].size();
    
    queue<pair<int, int>>q;

    visited[row][col]=1;
    q.push({row, col});
    
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int delr =-1; delr<=1; delr++){
            for(int delc=-1; delc<=1;delc++){
                int nrow = r+delr;
                int ncol = c+delc;
                if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && grid[nrow][ncol]=='1' && !visited[nrow][ncol]){
                    q.push({nrow, ncol});
                    visited[nrow][ncol]=1;
                }
            }
        }
    }
    
    
}

int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) {
        return 0;
    }

    int n = grid.size();
    int m = grid[0].size();
    int cnt = 0;
    
    vector<vector<int>> visited(n , vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && grid[i][j] == '1') {
                // Found a land cell, increment island count and perform DFS to mark the whole island
                cnt++;
                bfs(grid, visited, i, j);
            }
        }
    }

    return cnt;
}
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends