/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void inorder(TreeNode* root,string & data){
        if(!root)return ;
        data+=to_string(root->val)+',';
        inorder(root->left,data);
        inorder(root->right,data);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";

        inorder(root,ans);
      if(!ans.empty()) ans.pop_back();
        return ans;
    }
     TreeNode* insert(TreeNode*  root,int val){
        if(!root)return new TreeNode(val);
        if(root->val<val)root->right=insert(root->right,val);
        else root->left=insert(root->left,val);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int>preorder;
        int i=0;
        while(i<data.length()){
            int j=i;
            while(data[j]!=','&&j<data.length()){
                j++;
            }
            int value=stoi(data.substr(i,j-i));
            preorder.push_back(value);
            i=j+1;
        }
        TreeNode* root=NULL;
        for(int i=0;i<preorder.size();i++){
            root=insert(root,preorder[i]);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;