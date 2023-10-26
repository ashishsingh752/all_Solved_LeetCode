/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<vector<int>>v;
        ListNode* ansList= new ListNode(0);
        ListNode* temp = ansList;

        for(int i=0;i<lists.size();i++){
             ListNode* head = lists[i];
             vector<int>temp;
             while(head){
                 temp.push_back(head->val);
                 head=head->next;
             }
             head=NULL;
             v.push_back(temp);
             temp.clear();
        }

        // for(int i =0;i<v.size();i++){
        //     for(auto it: v[i]) {
        //         cout<<it<<" ";
        //     }cout<<endl;
        // }

        int n= v.size();  // row
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>>pq;
       
        for(int i =0;i<n;i++){
            if(v[i].size()>=1)pq.push({v[i][0], i});
            // cout<<"ashish"<<endl;
        }

        vector<int>ans;
        // while(!pq.empty()){
        //     cout<<pq.top().first<<" "<<pq.top().second<<endl;
        //     pq.pop();
        // }
        
        while(!pq.empty()){
            int element = pq.top().first;
            int index = pq.top().second;
            pq.pop();
            
            ans.push_back(element);
            v[index].erase(v[index].begin(), v[index].begin()+1);


            if(v[index].size()>=1){
              if(v.size()>=1)  pq.push({v[index][0], index});
            }
        }

        for(auto it: ans){
            ListNode*  dummy = new ListNode(it);
            temp->next = dummy;
            temp= temp->next;
        }
        return ansList->next;
        // return ansList->next;
    }
};