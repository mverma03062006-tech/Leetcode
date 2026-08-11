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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return NULL;
        TreeNode* node=root;
        TreeNode* parent=NULL;
        while(root){
            if(root->val==key)break;
            parent=root;
            if(root->val<key)root=root->right;
            else root=root->left;
        }
        if(!root)return node;
        if(!root->right){
            if(!parent)return root->left;
            if(parent->left==root)parent->left=root->left;
            else parent->right=root->left;
            return node;
        }
       TreeNode* temp=root->right;
       TreeNode*prev=root;
       while(temp->left){
        prev=temp;
        temp=temp->left;
       }
       root->val=temp->val;
       if(prev==root)prev->right=temp->right;
       else prev->left=temp->right;
        return node;
    }
};