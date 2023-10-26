class trie{
    public:
        int score;
        trie* v[26];
        trie(){
            score = 0;
            for(int i = 0; i < 26; i++){
                v[i] = NULL;
            }
        }
};
class Solution {
public:
    bool static cmp(vector<int> &a,vector<int> &b){
        if(a[0]==b[0])return a[1]<b[1];
        return a[0]>b[0];
    }
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        trie* node = new trie(),*tmp;
        for(auto &i: positive_feedback){
            tmp = node;
            for(auto &j: i){
                if(tmp->v[j-'a']==NULL){
                    tmp->v[j-'a'] = new trie();
                    tmp = tmp->v[j-'a'];
                }else{
                    tmp = tmp->v[j-'a'];
                }
            }
            tmp->score = 3;
        }
        for(auto &i: negative_feedback){
            tmp = node;
            for(auto &j: i){
                if(tmp->v[j-'a']==NULL){
                    tmp->v[j-'a'] = new trie();
                    tmp = tmp->v[j-'a'];
                }else{
                    tmp = tmp->v[j-'a'];
                }
            }
            tmp->score = -1;
        }
        int n = student_id.size(),j,scr = 0,i;
        bool a = true;
        vector<vector<int>> ans;
        for(i = 0; i < n; i++){
            scr = 0;
            tmp = node;
            a = true;
            for(j = 0; j <= report[i].length(); j++){
                if(j == report[i].length() || report[i][j] == ' '){
                    if(a){
                        scr += tmp->score;
                    }
                    // cout<<scr<<" ";
                    tmp = node;
                    a = true;
                }else{
                    if(tmp->v[report[i][j]-'a'] == NULL){
                        a = false;
                    }else{
                        tmp = tmp->v[report[i][j]-'a'];
                    }
                }
            }
            // cout<<endl;
            ans.push_back({scr,student_id[i]});
        }
        sort(ans.begin(),ans.end(),cmp);
        // for(auto &i: ans){
        //     cout<<i[0]<<" "<<i[1]<<endl;
        // }cout<<endl;
        vector<int> xx;
        for(i = 0; i < k; i++){
            xx.push_back(ans[i][1]);
        }
        return xx;
    }
};