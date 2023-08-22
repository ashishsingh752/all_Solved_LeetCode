class Solution {
    void bfs(vector<vector<int>>& grid, vector<vector<int>>&visited,  int i, int j,int val,  int color){

        queue<pair<int, int>>q;
        int n = grid.size();
        int m = grid[0].size();

        q.push({i, j});
        visited[i][j]=1;

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            // grid[row][col]=color;

            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};
            visited[row][col]=1;
            for(int r=0;r<4;r++){
                int nrow = row + dr[r];
                int ncol = col + dc[r];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==val&& !visited[nrow][ncol]) {
                    grid[nrow][ncol]=color;
                    visited[nrow][ncol]=1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int val = image[sr][sc];
        image[sr][sc]=color;
        vector<vector<int>>visited(n, vector<int>(m, 0));
        bfs(image, visited, sr, sc ,val, color);
        return image;
    }
};