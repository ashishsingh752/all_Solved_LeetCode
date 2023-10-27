class Solution {

bool check(vector<vector<bool>> &dp, string &s, int i, int j){
    if(i==j) return dp[i][j]=true;
    // if(i>j) return dp[i][j]=false;
    if(j-i==1){
        if(s[i]==s[j]) return dp[i][j]=true;
        else return dp[i][j]=false;
    }
    if(s[i]==s[j]&& dp[i+1][j-1]!=false){
        return dp[i][j]=true;
    }
    else return dp[i][j]=false;
}

public:
    string longestPalindrome(string s) {
        int len=0;
        int ind=0;
        int n=s.size();
        vector<vector<bool>> dp(n, vector<bool>(n,false));
        for(int k=0;k<n;k++){
            for(int j=k, i=0;j<n;i++,j++){
                check(dp, s, i, j);
                if(dp[i][j]){
                    int a=(j-i+1);
                    if(a>len){
                        len=j-i+1;
                        ind=i;
                    }
                }
            }
        }
        return s.substr(ind, len);
    }
};