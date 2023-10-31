class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int>ans; 
        int size = pref.size();
        if(size<=1) return pref;
        ans.push_back(pref[0]);
        for(int i  =1;i<size;i++){
            ans.push_back(pref[i]^pref[i-1]);
        }
        return ans;
    }
};