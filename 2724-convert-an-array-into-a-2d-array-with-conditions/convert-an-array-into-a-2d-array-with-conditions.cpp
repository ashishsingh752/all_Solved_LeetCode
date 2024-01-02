class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int, int> mp;
        int cnt = 0;
        int size = nums.size();
        
        for (auto it : nums) {
            mp[it]++;
            cnt = max(cnt, mp[it]);
        }
      
        vector<vector<int>> ans(cnt);
        vector<int> v(size+1, 0);
       
        for (int i = 0; i < size; i++) {
            ans[v[nums[i]]].push_back(nums[i]);
            v[nums[i]]++;
        }

        // for(auto it: mp){
        //   int j= 0;
        //     while(it.second){
        //         ans[j].push_back(it.first);
        //         it.second--;
        //         j++;
        //     }
        // }

        return ans;
    }
};