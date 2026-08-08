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
void inorder(TreeNode* root, vector<pair<int,pair<int,int>>>& index,int row,int col){
    if(!root)return;
    index.push_back({root->val,{row,col}});
    inorder(root->left,index,row+1,col-1);
    inorder(root->right,index,row+1,col+1);
}
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<pair<int,pair<int,int>>>index;
        vector<vector<int>>ans;
        inorder(root,index,0,0);
        sort(index.begin(),index.end(),[](const auto& a,const auto& b){
            if(a.second.second!=b.second.second){
                return a.second.second<b.second.second;
            }
            if(a.second.first!=b.second.first){
                return a.second.first<b.second.first;
            }
            return a.first<b.first;
        });
        int col=index[0].second.second;
        vector<int>level;
        for(int i=0;i<index.size();i++){
            if(index[i].second.second==col){
                level.push_back(index[i].first);
            } 
            else {
                ans.push_back(level);
                level.clear();
                col=index[i].second.second;
                level.push_back(index[i].first);
            }          
        }
        ans.push_back(level);
        return ans;
    }
};