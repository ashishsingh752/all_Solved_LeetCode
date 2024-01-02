class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int>mp;
        int cnt=0;
        int size = nums.size();
        for(int i=0;i<size; i++){
            mp[nums[i]]++;
            cnt = max(cnt, mp[nums[i]]);
        }
        vector<vector<int>>ans(cnt);
        for(auto it: mp){
          int j=0;
            while(it.second){
                ans[j].push_back(it.first);
                it.second--;
                j++;
            }
        }
        return ans;
    }

};