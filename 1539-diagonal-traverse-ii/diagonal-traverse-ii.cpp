class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row=mat.size();
        map<int, vector<int>> m;
        for(int i=0;i<row;i++){
            int col=mat[i].size();
            for(int j=0;j<col;j++){
                if(mat[i][j]!=0)
                m[i+j].push_back(mat[i][j]);
            }
        }
        vector<int> ans;
        for(auto it: m){
            if(it.first%2==0){
                reverse(it.second.begin(), it.second.end());
                for(auto i: it.second) ans.push_back(i);
            }
            else {
                reverse(it.second.begin(), it.second.end());
                for(auto i: it.second) ans.push_back(i);
            }
        }

        return ans;

    }
};