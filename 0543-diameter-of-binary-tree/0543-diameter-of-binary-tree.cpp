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
void preorder(int& ans,TreeNode* root){
        if(root==NULL)return ;
        
        preorder(ans,root->left);
        ans=max(maxDepth(root->left)+maxDepth(root->right),ans);
        preorder(ans,root->right);
    }
 int maxDepth(TreeNode* root) {
        if(!root)return 0;
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        preorder(ans,root);
        return ans;
    }
};