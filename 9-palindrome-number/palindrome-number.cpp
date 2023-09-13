class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        long long int a = x;
        long long int b =0;
        while(a){
            b=b*10+a%10;
            a=a/10;
        }
        if(b==(long long int)x)return true;
        return false;
    }
};