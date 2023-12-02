class Solution { 
public:
    int countCharacters(vector<string>& words, string chars) {
        
        int k=0;
        int ans=0;
        for(auto &i : words){
            int arr[26]={};
            for(char ch : chars){ 
              int c = ch - 'a';
              arr[c]++;
            }
            for(auto j : i){
                int c = j - 'a';
                if(arr[c] != 0){
                    k=i.size();
                    arr[c]--;
                }
                else if (arr[c]==0){
                    k=0;
                    break;
                }
            }
            ans=ans+k;
        }
        return ans;
    }
}; // Please Upvote