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
    unordered_map<int,int>map;
    int post;

    TreeNode* build(vector<int>& inorder, vector<int>& postorder,int l,int r){
        if(l>r)return NULL;
        int value=postorder[post--];
        TreeNode* root=new TreeNode (value);

        int pos=map[value];
        root->right=build(inorder,postorder,pos+1,r);
        root->left=build(inorder,postorder,l,pos-1);
      
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++){
            map[inorder[i]]=i;
        }
        post=postorder.size()-1;
        return build(inorder,postorder,0,inorder.size()-1);
    }
};