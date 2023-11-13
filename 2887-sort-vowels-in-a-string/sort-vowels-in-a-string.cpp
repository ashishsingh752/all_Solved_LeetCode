class Solution {
public:
    string sortVowels(string s) {
        vector<char> arr; 
        for(int i=0;i<s.size();i++){
            char ch= s[i];
            if(ch=='A' || ch=='E' ||ch=='I' ||ch=='O' ||ch=='U' ||ch=='a' ||ch=='e' ||ch=='i' ||ch=='o' ||ch=='u'){
               arr.push_back(ch);
            }
        }
        sort(arr.begin(), arr.end());
        
        
        int t=0;
        string str="";
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(ch=='A' || ch=='E' ||ch=='I' ||ch=='O' ||ch=='U' ||ch=='a' ||ch=='e' ||ch=='i' ||ch=='o' ||ch=='u'){
                str.push_back(arr[t++]);
            }else str.push_back(s[i]);
        }
        return str;
        
    }
};