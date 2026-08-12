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
    int pre=0;

    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int l,int r){
        if(l>r)return NULL;
        int value=preorder[pre++];
        TreeNode* root=new TreeNode (value);

        int pos=map[value];
        root->left=build(preorder,inorder,l,pos-1);
        root->right=build(preorder,inorder,pos+1,r);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<preorder.size();i++){
            map[inorder[i]]=i;
        }
        return build(preorder,inorder,0,inorder.size()-1);
    }
};