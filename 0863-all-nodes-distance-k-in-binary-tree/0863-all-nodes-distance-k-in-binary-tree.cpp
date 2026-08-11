/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root)return {};
        unordered_map<TreeNode*,TreeNode*>Parent;
        mapparent(root,Parent);
        return tar(target,Parent,k);
    }
    void mapparent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& Parent){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->left){
                Parent[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                Parent[node->right]=node;
                q.push(node->right);
            }
        }
    }
    vector<int> tar(TreeNode* root,unordered_map<TreeNode*,TreeNode*> & Parent,int k){
        queue<TreeNode*>q;
        unordered_set<TreeNode*>visited;
        q.push(root);
        visited.insert(root);
        int curr=0;
        while(!q.empty()){
            int size=q.size();
            if(curr++==k)break;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left&&visited.find(node->left)==visited.end()){
                    visited.insert(node->left);
                    q.push(node->left);
                }
                if(node->right&&visited.find(node->right)==visited.end()){
                    visited.insert(node->right);
                    q.push(node->right);
                }
                if(Parent.count(node)&&visited.find(Parent[node])==visited.end()){
                    visited.insert(Parent[node]);
                    q.push(Parent[node]);
                }
            }

        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};