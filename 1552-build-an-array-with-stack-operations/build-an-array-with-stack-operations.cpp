class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans; 
        int size = target.size();
        // for(int i=0;i<size;i++){

        // }

         int i =0, j=1;
        while(i<size){
            while(target[i]!=j){
                ans.push_back("Push");
                ans.push_back("Pop");
                j++;
            }
            if(target[i]==j){
                ans.push_back("Push");
                j++;
            }
            i++;
        }
        return ans; 
    }
};