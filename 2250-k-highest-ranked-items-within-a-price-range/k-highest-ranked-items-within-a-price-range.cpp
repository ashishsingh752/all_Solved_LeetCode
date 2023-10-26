class Solution {
public:

vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& p, vector<int>& s, int k)
{
     vector<vector<int>> res;
     vector<vector<int>> ans;
     int n = grid.size() , m  = grid[0].size(); 
     vector<vector<int>> v(n,vector<int>(m,0)); // visited array 

     int l = p[0] , u = p[1] ; // range of price 
      if(grid[s[0]][s[1]]<=u && grid[s[0]][s[1]]>=l) // if the starting point is in the price range 
      {
          res.push_back({0,grid[s[0]][s[1]],s[0],s[1]});
      }
     queue<pair<int,pair<int,int>>> q; // {step,{row,col}}
     q.push({0,{s[0],s[1]}});
     v[s[0]][s[1]] = 1; 
     int dr[]  = {1,-1,0,0};
     int dc[]  = {0,0,1,-1};// both array for adjacent traversal in matrix 

     while(q.size())
     {
         int step = q.front().first;
         int row = q.front().second.first;
         int col = q.front().second.second;
         q.pop();
         for(int i = 0 ; i<4;i++)
         {
             int nr = row + dr[i];
             int nc = col + dc[i];
             if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]!=0 && v[nr][nc]==0)
             {
                 q.push({step+1,{nr,nc}});
                 v[nr][nc] =1; 
                 if(grid[nr][nc]!=1 && grid[nr][nc]>=l && grid[nr][nc]<=u ) // we only push if price is under 
//limit and for price outside limit we just traverse across to go to other cell
                 {
                     res.push_back({step+1,grid[nr][nc],nr,nc});//{step,price,row,col}
                 }
             }
         }
      }

      sort(res.begin(),res.end());
      for(int i = 0; i<res.size() && k; i++,k--)
      ans.push_back({res[i][2],res[i][3]});
      return ans; 


}
};