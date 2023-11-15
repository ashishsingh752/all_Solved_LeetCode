class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        if(arr[0]!=1)arr[0]=1;
        int n =arr.size(), ans=1;
        for(int i =1;i<n;i++){
            int val = abs(arr[i]-arr[i-1]);
            if(val>1){
                arr[i]=arr[i-1]+1;
                ans=arr[i];
            }else{
                ans=arr[i];
            }
        }
        return ans; 
    }
};