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
   
    // void preorder(TreeNode* root, int& sum, int&len){
    //     if(root==NULL) return;
    //     if(root->left) preorder(root->left, sum, len);
    //     len++;
    //     if(root) sum+=root->val;
    //     if(root->right) preorder(root->right, sum, len);
    // }

    // void inorder(TreeNode* root, int&cnt){
    //     if(root==NULL) return ;
    //     if(!root->left&& !root->right){
    //         cnt++;
    //         return ;
    //     }

    //     int ll=0, lr=0, sl=0, sr=0;
    //     int val = root->val;
       
    //     if(root->left){
    //         TreeNode* temp = root->left;
    //         preorder(temp, sl, ll);
    //         inorder(root->left, cnt);
    //     }

    //     if(root->right){
    //         TreeNode* temp = root->right;
    //         preorder(temp, sr, lr);
    //         inorder(root->right, cnt);
    //     }
    //     int sum = sr+sl;
    //     int len = ll+lr;
    //     if(val==(sum/len)) cnt++;
    // }

  private: 
    pair<int,int> subTree(TreeNode* root, int &cnt){
        if(root==NULL){
            return {0,0};
        }

        pair<int, int> left = subTree(root->left, cnt);
        pair<int, int> right = subTree(root->right, cnt);
        int len = left.second+right.second+1;
        int sum = left.first+right.first+root->val;
        
        if(root->val == sum/len) cnt++;
        return   {sum, len};
    }

public:
    int averageOfSubtree(TreeNode* root) {
          int cnt=0;
          pair<int, int> p = subTree(root, cnt);
          return cnt;
    }
};