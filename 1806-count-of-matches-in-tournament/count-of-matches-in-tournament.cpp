class Solution {
public:
    int numberOfMatches(int n) {
        int m = n;
        long long  int ans = 0;
        while(m!=1){
            ans+=(m/2);
            m=m-m/2;
        }
        return ans;
    }
};