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
    void backtrack(TreeNode* root,vector<vector<int>>& ans,vector<int>& path,int target){
        if(!root) {
            return;
        }
        path.push_back(root->val);
        target-=root->val;
        if(!root->left&&!root->right){
            if(target==0)ans.push_back(path);
        }
        else {
        backtrack(root->left,ans,path,target);
        backtrack(root->right,ans,path,target);
        }
        path.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>path;
        backtrack(root,ans,path,targetSum);
        return ans;
    }
};