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
    void cntgood(TreeNode* root,int max,int& count){
        if(!root)return;
        if(root->val>=max){
            count++;
            max=root->val;
        }
        cntgood(root->left,max,count);
        cntgood(root->right,max,count);
    }
    int goodNodes(TreeNode* root) {
        int count=1;
        cntgood(root->right,root->val,count);
        cntgood(root->left,root->val,count);
        return count;
    }
};