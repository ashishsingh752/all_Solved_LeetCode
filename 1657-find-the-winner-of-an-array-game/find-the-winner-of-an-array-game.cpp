class Solution {
    
#define MOD 1000000007
public:
    int getWinner(vector<int>& arr, int k) {
        unordered_map<int, int>mp ;
        int i =0;
        int n  = arr.size();
     
        if(k>n){
            int val = INT_MIN;
            for(auto it: arr){
                val = max(val, it);
            }
            return val;
        }

        // k=k%MOD;
        // while(mp[val]!=k){
        //     if(arr[0]>arr[1]){
        //         val = arr[0];
        //         int temp = arr[1];
        //         mp[val]++;
        //         for(int i =2;i<n;i++){
        //             swap(arr[i],arr[i-1]);
        //         }
        //     }
        //     else{
        //         val = arr[1];
        //         mp[val]++;
        //         int temp = arr[0];
        //         for(int i = 0;i<n-1;i++){
        //             swap(arr[i],arr[i+1]);
        //         }
        //     }
        // }
        
        int cnt  = 0;
        int val = max(arr[0], arr[1]);
        for( int i = 1; i<n; i++ ){
            if(arr[i]>val ){
                val = arr[i];
                cnt  = 1; 
            }
            
            else cnt++ ;
            
            if(cnt==k) return val;
        }
        return val;
    }
};