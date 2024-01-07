class Solution {
    int solve(vector<int>arr, int mid){
	int ans = 0;
	for(auto it: arr){
		int val = ceil(double(it)/double(mid));
		ans+=val;
	}
	return ans;
    }

public:
    int smallestDivisor(vector<int>& arr, int limit) {
        int mini = INT_MAX;
	    int maxi = INT_MIN;
	for(auto it: arr){
		mini = min(mini, it);
		maxi = max(maxi, it);
	}
        int ans=-1 ;
        int start = 1, end = maxi ;
	while(start<=end){
		double mid = start+(end-start)/2;
		 int  val = solve(arr, mid);
		if(val>limit){
            // ans = val;
            start=mid+1;
        }
		else end = mid-1;
	}
	    return start;
    }
};