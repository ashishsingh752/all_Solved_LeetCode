class Solution {
    void bfs(int row, int col, vector<vector<char>>&grid,vector<vector<int>>&visited){
        visited[row][col]=1;

        queue<pair<int, int>>q;
        int n=grid.size();
        int m  = grid[0].size();

        q.push({row, col});

        while(!q.empty()){
            int nrow = q.front().first;
            int ncol = q.front().second;
            q.pop();

            visited[nrow][ncol]=1;
            int dr[] = {1, -1, 0, 0};
            int dc[] = {0, 0, 1, -1};

            for (int i = 0; i < 4; i++) {
                int newRow = nrow + dr[i];
                int newCol = ncol + dc[i];

   if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == '1' && !visited[newRow][newCol]) {
                    visited[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }

    //     if(nrow+1<n && nrow-1>=0  && ncol+1<m && ncol-1>=0 && grid[nrow+1][ncol+1]=='1' && !visited[nrow+1][ncol+1]){
    //         q.push({nrow+1, ncol+1});
    //         visited[nrow+1][ncol+1]=1;
    //     }
    //    else  if(nrow+1<n && nrow-1>=0  && ncol+1<m && ncol-1>=0 && grid[nrow-1][ncol-1]=='1' && !visited[nrow-1][ncol-1]){
    //         q.push({nrow-1, ncol-1});
    //         visited[nrow-1][ncol-1]=1;
    //     }
    //   else  if(nrow+1<n && nrow-1>=0  && ncol+1<m && ncol-1>=0 && grid[nrow][ncol+1]=='1' && !visited[nrow][ncol+1]){
    //         q.push({nrow, ncol+1});
    //         visited[nrow][ncol+1]=1;
    //     }
    //    else if(nrow+1<n && nrow-1>=0  && ncol+1<m && ncol-1>=0 && grid[nrow+1][ncol]=='1' && !visited[nrow+1][ncol]){
    //         q.push({nrow+1, ncol});
    //         visited[nrow+1][ncol]=1;
    //     }

        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n, vector<int>(m,0));
        
        int cnt =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                   cnt++;
                   bfs(i, j, grid, visited);
                }
            }
        }
        return cnt;
    }
};