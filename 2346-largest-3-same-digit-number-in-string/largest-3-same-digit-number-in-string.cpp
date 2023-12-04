class Solution {
public:
    string largestGoodInteger(string num) {
        vector<string>v={"111", "222", "333", "444", "555", "666", "777", "888", "999", "000"};

        int ans = INT_MIN;
        string temp = "";
        for(int i=2; i<num.size(); i++){
            if(num[i]==num[i-1] && num[i-1]==num[i-2]){
                temp.push_back(num[i]);
                temp.push_back(num[i]);
                temp.push_back(num[i]);
                int val = stoi(temp);
                ans = max(ans, val);
            }
            temp="";
        }
        string  t = "";
        if(ans==0){
            t.push_back('0');
            t.push_back('0');
            t.push_back('0');
            return t; 
        }
        if(ans ==INT_MIN) return "";
        while(ans){
            char c = ans%10+'0';
            t.push_back(c);
            ans=ans/10;
        }
        return t; 

    }
};