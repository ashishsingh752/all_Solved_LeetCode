class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        int i=0;
        int j=0; 
        int n= s.length();
        int m=t.length();
        int cnt=0;
        if(n!=m){
            return 0;
        }
        while(i<n && j<m){
            if(s[i++]!=t[j++]) {
                return 0;
            }
            else cnt++;
        }
        if(cnt==n){
            return 1; 
        }
        return 0;

    }
};