class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,string>mp;
        string des = paths[0][1];
        string src = paths[0][0];
        int size = paths.size();
        for(int i =0;i<size;i++){
            mp[paths[i][0]]=paths[i][1];
        }

        string st=mp[src];
        while(mp[st]!=""){
             st = mp[src];
             src=st;
        }
        
        return st;
    }
};