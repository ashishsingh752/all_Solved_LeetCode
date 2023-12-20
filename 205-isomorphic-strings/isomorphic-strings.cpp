class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;
        int n = s.size(), m=t.size();
        if(n!=m)return false;

        for(int i =0;i<n;i++){
          if(mp1.find(s[i])==mp1.end() && mp2.find(t[i])==mp2.end()){
              mp1[s[i]]=t[i];
              mp2[t[i]]=s[i];
          }
          else {
              if(mp2[t[i]]!=s[i])return false;
          }
        }
      
        return true;
    }
};