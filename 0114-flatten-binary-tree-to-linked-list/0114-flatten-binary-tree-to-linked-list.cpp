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
TreeNode * prev=NULL;
    void preorder(TreeNode* root){
        if(!root)return;
         TreeNode* left = root->left;
        TreeNode* right = root->right;
        if(prev!=NULL){
        prev->left=NULL;
        prev->right=root;
        }
        
        prev=root;
        preorder(left);
        preorder(right);
        
        
    }
    void flatten(TreeNode* root) {
        
        preorder(root);
    }
};