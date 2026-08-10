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
    void inorder(TreeNode* root,vector<int>& ans){
        if(!root)return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>ans;
        inorder(root,ans);
        int i=0,j=ans.size()-1;
        while(j>i){
            if(ans[j]+ans[i]==k)return true;
            else if(ans[j]+ans[i]<k)i++;
            else j--;
        }
        return false;
    }
};