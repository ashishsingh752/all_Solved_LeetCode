class Solution {
public:
    string largestOddNumber(string num) {
        string ans = "";
        int index = -1;
        int size = num.size();
        for(int i = size-1; i>=0;i--){
            int val = num[i]-'0';
            if(val%2!=0){
                index = i; 
                break;
            }
        }
        if(index ==-1) return "";
        else {
            for(int i =0;i<=index ;i++){
                ans.push_back(num[i]);
            }
        }
        return ans;
    }
};