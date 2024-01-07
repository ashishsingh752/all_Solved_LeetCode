class Solution {
    long long int solve(vector<int>&weights, int mid){
        int daysCount = 0;
        int sum = 0;
        int size = weights.size();

        for(int i =0;i<size-1;i++){
            sum+=weights[i];
            if(sum+weights[i+1]>mid && sum<=mid){
                daysCount++;
                sum=0;
            }
        }
        if(sum<=mid)return daysCount+1;
        return daysCount;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxWeight= INT_MIN;
        int sum =0;
        for(auto it: weights){
             maxWeight= max(maxWeight, it);
             sum+=it;
        }
        int ans = -1;
        int start = maxWeight , end = sum;
        while(start<=end){
            long long int mid= start+(end-start)/2;
           long long int dayCount = solve(weights, mid);
            if(dayCount<=days){
                ans=mid;
                end=mid-1;
            }
            else start = mid+1;
        }
        return ans;
    }
};