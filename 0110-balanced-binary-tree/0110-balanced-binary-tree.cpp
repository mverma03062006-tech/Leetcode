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
bool preorder(TreeNode* root){
        if(root==NULL)return true;
        
        if(!preorder(root->left))return false;
        if(abs(maxDepth(root->left)-maxDepth(root->right))>1)return false ;
         if(!preorder(root->right))return false;
         return true;
    }
   
     int maxDepth(TreeNode* root) {
        if(!root)return 0;
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
    bool isBalanced(TreeNode* root) {
        
        return preorder(root);
    }
};