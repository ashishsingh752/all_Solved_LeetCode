class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>v; 
        map<int, int>mp;
        for(auto it: nums){
            mp[it]++;
        }
        for(auto it: mp){
            // cout<<it.first<<" "<<it.second<<endl;
            v.push_back(it.second);
        }
        int n = v.size();
        for(int i=n-2; i>=1;i--){
            v[i]=v[i]+v[i+1];
            // cout<<v[i]<<" ";
        }
        int sum =0;
        for(int i =1;i<n;i++) {
            sum+=v[i];
        }
        return sum;

    }
};