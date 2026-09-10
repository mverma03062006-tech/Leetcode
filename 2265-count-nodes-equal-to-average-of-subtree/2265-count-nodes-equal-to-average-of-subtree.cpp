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
void dfs2(TreeNode* root,int& sum,int& count){
    if(!root)return ;
    sum+=root->val;
    count++;
    dfs2(root->left,sum,count);
    dfs2(root->right,sum,count);
}
    void dfs(int& ans,TreeNode* root){
        if(!root)return;
        int sum=root->val;
        int count=1;
        dfs2(root->left,sum,count);
        dfs2(root->right,sum,count);
        if(sum/count==root->val)ans++;
        dfs(ans,root->left);
        dfs(ans,root->right);
    }
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        dfs(ans,root);
        return ans;
    }
};