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
 class info{
    public:
    bool isbst;
    int min;
    int max;
    int sum;
 };
class Solution {
public:
    
    info postorder(TreeNode* root,int & ans){
        if(!root)return {true,INT_MAX,INT_MIN,0};
        info left=postorder(root->left,ans);
        info right=postorder(root->right,ans);
        info curr;
        curr.sum=left.sum+right.sum+root->val;
        curr.min=min(root->val,left.min);
        curr.max=max(root->val,right.max);
        curr.isbst=left.isbst&&right.isbst&&root->val>left.max&&root->val<right.min;
        if(curr.isbst)ans=max(ans,curr.sum);
        return curr;
    }
    int maxSumBST(TreeNode* root) {
        int ans=0;
        postorder(root,ans);
        return ans;
    }
};