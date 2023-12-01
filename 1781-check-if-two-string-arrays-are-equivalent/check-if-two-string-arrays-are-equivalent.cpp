class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str1 ="";
        string str2 ="";
        for(auto it: word1) str1+=it;
        for(auto it: word2) str2+=it;
        if(str1.size()!=str2.size()) return false;
        for(int i =0;i<str1.size(); i++)
        if(str1[i]!=str2[i]) return false; 
        return true; 

    }
};