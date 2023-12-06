class Solution {
public:
    int totalMoney(int n) {
        if(n<=7) return n*(n+1)/2;
        else {
            int t = n/7;
            int b = n%7;
            return 28*t+ t*7*(t-1)/2+t*b+b*(b+1)/2;
        }
    }
};