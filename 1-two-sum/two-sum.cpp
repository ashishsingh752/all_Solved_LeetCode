class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // vector<int> ans;
       vector<pair<int, int>>p;
       for(int i=0;i<nums.size();i++){
           p.push_back({nums[i], i});
       }
       sort(p.begin(), p.end());
        int i=0,j=p.size()-1;
        while(i<j){
            int  a = p[i].first;
            int  b = p[j].first;
            if(a+b==target)return {p[i].second, p[j].second};
            else if(a+b<target)i++;
            else j--;
        }
        return {};
    }
};