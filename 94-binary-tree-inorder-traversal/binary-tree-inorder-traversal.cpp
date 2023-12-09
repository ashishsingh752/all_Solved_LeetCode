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
public:
    // time/space: O(n)/O(1)
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* curr = root;
        while (curr != NULL) {
            if (curr->left == NULL) {
                result.push_back(curr->val);
                curr = curr->right;
            }
            else {
                // find the right-most node from the left node
                TreeNode* node = curr->left;
                while ((node->right != NULL) && (node->right != curr)) node = node->right;
                
                // magic
                if (node->right == NULL) {
                    // connect to the current node `curr`
                    node->right = curr;
                    curr = curr->left;
                }
                else {
                    // revert the connection
                    node->right = NULL;
                    // the left nodes of the current node `curr` are all done
                    result.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return result;
    }
};