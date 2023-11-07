class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double>v; 
        int n = dist.size();
        for(int i = 0;i<n;i++){
            double time = ((double)dist[i]/(double)speed[i]);
            v.push_back(time);
        }
        sort(v.begin(), v.end());
         int t=0, ans=0;
         for(auto it: v){
             if(it<=t){
                 break;
             }else{
                 t++; 
                 ans++;
             }
         }
        return ans; 
    }
};