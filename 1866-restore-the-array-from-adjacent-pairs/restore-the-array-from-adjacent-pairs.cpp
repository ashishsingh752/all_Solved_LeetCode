class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs){
       unordered_map<int, vector<int>>mp; 
       vector<int>ans;
       vector<int>temp ; 
       for(auto it: adjacentPairs){
           mp[it[0]].push_back(it[1]);
           mp[it[1]].push_back(it[0]);
       }

       for(auto it: mp){
           if(it.second.size()==1){
               temp.push_back(it.first);
           }
       }
       for(auto it:temp)cout<<it<<" ";

       map<int , bool>m; 
        int val = temp[0];
        // ans.push_back(val);
        m[val]=true;
        int n= adjacentPairs.size()+1;
        
        while(ans.size()!=n){
            // if(!m[val]){
            //     m[val]=true;
            //     if(m[mp[val]])
            // }
            auto it = mp[val];
            ans.push_back(val);
            if(!m[it[0]]){
                int t = it[0];
                val=t;
                m[val]=true;
            }
            else if(it.size()==2 &&  !m[it[1]]){
                val  = it[1];
                m[val]=true;
            }

        }
       return ans;

    }
};