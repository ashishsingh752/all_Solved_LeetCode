class Solution {
public:
    typedef long long ll;
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);
        map<ll, ll> mp1, mp2, mp3, mp4;
        
        for(int i=0; i<n; i++){
            mp1[nums[i]]+=i;
            mp4[nums[i]]++;
        }
    
        for(int i=0; i<n; i++){
            mp2[nums[i]]++;
            mp3[nums[i]]+=i;
            ll fre = mp2[nums[i]];
            ll count = mp3[nums[i]];
            ll sum=0;
        
            sum = i*(fre) - 2*count  + mp1[nums[i]] - i*(mp4[nums[i]] - fre);
            
            ans[i] = sum;
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<long long> distance(vector<int>& nums) {
//         unordered_map<long long, vector<long long>>mp;
//         long long n=nums.size();
//         for(long long i=0;i<n;i++){
//             mp[nums[i]].push_back(i);
//         }

//         vector<long long>ans;
//         for(long long i=0;i<n;i++){
//             long long sum=0;
//             for(auto a:mp[nums[i]]){
//                 sum+=abs(i-a);
//             }
//             ans.push_back(sum);
//         }
//         return  ans;        

//     }
// };