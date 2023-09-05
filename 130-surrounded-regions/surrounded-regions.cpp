class Solution {
    void dfs(int row, int col, vector<vector<char>>&grid, vector<vector<int>>&visited){
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

if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 'O' && !visited[newRow][newCol]){
                    visited[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
    }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>visited(n, vector<int>(m, 0));
        queue<pair<int, int>>q; 

        // taking the elements with the zero at the end
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && board[i][j]=='O') q.push({i, j});
                else if(j==0 && board[i][j]=='O')q.push({i, j});
                else if(i==n-1 && board[i][j]=='O')q.push({i, j});
                else if(j==m-1 && board[i][j]=='O')q.push({i, j});
            }
        }


        while(!q.empty()){
            auto temp = q.front();

            q.pop();
            int idx = temp.first;
            int idy= temp.second;
            cout<<idx<<" "<<idy<<endl;
            dfs(idx, idy, board, visited);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
    }
};