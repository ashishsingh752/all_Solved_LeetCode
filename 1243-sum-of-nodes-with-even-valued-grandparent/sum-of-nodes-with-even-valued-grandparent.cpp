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
      void f(TreeNode* root, int&sum){
        if(root==NULL)return ;
        if(!root->left && !root->right) return ;
        // else if(!root->left->left && !root->right->right) return ;
        if(root->val%2==0){
            if(root->left){
                if(root->left->left)
                sum+=root->left->left->val;
                if(root->left->right)
                sum+=root->left->right->val;
                f(root->left, sum);
            }
            if(root->right){
                if(root->right->left)
                sum+=root->right->left->val;
                if(root->right->right)
                sum+=root->right->right->val;
                f(root->right, sum);
            }
        }else{
            if(root->left) f(root->left, sum);
            if(root->right) f(root->right, sum);
        }

      }
public:
    int sumEvenGrandparent(TreeNode* root) {
        if(root==NULL)return 0;
        int sum=0;
        f(root, sum);
        return sum ;
    }
};