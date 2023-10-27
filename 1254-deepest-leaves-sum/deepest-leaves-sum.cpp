/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private: 
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
            if (root == NULL) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size= q.size();
            vector<int>v;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                v.push_back(node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            ans.push_back(v);
        }

        return ans;
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        vector<vector<int>>v = levelOrder(root);
        int sum=0;
         for(auto it: v[v.size()-1]){
             sum+=it;
         }
         return sum;
    }
};