class Solution {
        long long int  maxiHour(vector<int >&v){
       int  ans = INT_MIN;
        for(auto it:v) ans= max(ans, it);
        return ans; 
    }
  
    double f(vector<int>&v, int val ){
        long long int ans = 0;
        for(auto it: v){
            ans+= ceil(double(it)/double(val));
        }
        return ans;
    }
public:
    int minEatingSpeed(vector<int>& v, int h) {
        long long int start =  1, end = maxiHour(v);
        while(start<=end){
            long long int mid  = start+(end-start)/2;
            double val = f(v, mid);
            if(val<=h)end = mid-1;
            else start = mid+1;
        }return start;  
    }
};