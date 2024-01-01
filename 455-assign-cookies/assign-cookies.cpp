class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0;
        for(int i = 0;i<g.size();i++){
            for(int j =0;j<s.size();j++){
                if(g[i]<=s[j]){
                    ans++;
                    s.erase(s.begin()+j);
                    break;
                }
            }
        }
        return ans;
    }
};