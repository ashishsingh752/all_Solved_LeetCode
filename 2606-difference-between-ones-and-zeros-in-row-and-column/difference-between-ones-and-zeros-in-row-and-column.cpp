class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<pair<int,int>>rowMat;
        vector<pair<int,int>>colMat;
        
        for(int i =0;i<n;i++){
            int cnt1=0, cnt0=0;
            for(int j =0;j<m;j++){
                if(grid[i][j]==0){
                    cnt0++;
                }else if(grid[i][j]==1){
                    cnt1++;
                }
            }
            rowMat.push_back({cnt0,cnt1});
        }
        
        for(int i =0;i<m;i++){
            int cnt1=0, cnt0=0;
            for(int j =0;j<n;j++){
                if(grid[j][i]==0){
                    cnt0++;
                }else if(grid[j][i]==1){
                    cnt1++;
                }
            }
            colMat.push_back({cnt0,cnt1});
        }

        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
               auto rt = rowMat[i];
               auto ct = colMat[j];
               int diff =(rt.second+ct.second)-(rt.first+ct.first );
               ans[i][j]=diff;
            }
            
        }
        
        return ans;
    }
};