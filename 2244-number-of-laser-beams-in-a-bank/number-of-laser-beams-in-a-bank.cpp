class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans =0;
        int m =bank.size();
        int n = bank[0].size();
        int cnt = 0;
        for(auto it: bank[0]){
            if(it-'0'==1)cnt++;
        }
        int prev= cnt;
        for(int i =1;i<m;i++){
            int a = 0;
            for(auto it: bank[i]){
                if(it-'0'==1)a++;
            }
           if(a!=0){ 
               ans+=prev*a;
               prev=a;
            }
        }
        return ans;
    }
};