class Codec {
public:

    string serialize(TreeNode* root) {
        if (!root) return "";

        string ans = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            if (temp == NULL) {
                ans += "#,";
            }
            else {
                ans += to_string(temp->val) + ",";
                q.push(temp->left);
                q.push(temp->right);
            }
        }

        return ans;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;

        vector<string> v;
        string temp = "";

        for (int i = 0; i < data.size(); i++) {
            if (data[i] == ',') {
                v.push_back(temp);
                temp = "";
            }
            else {
                temp += data[i];
            }
        }

        if (!temp.empty())
            v.push_back(temp);

        TreeNode* root = new TreeNode(stoi(v[0]));

        queue<TreeNode*> q;
        q.push(root);

        int i = 1;

        while (!q.empty() && i < v.size()) {
            TreeNode* curr = q.front();
            q.pop();

            if (v[i] != "#") {
                curr->left = new TreeNode(stoi(v[i]));
                q.push(curr->left);
            }

            i++;

            if (i < v.size() && v[i] != "#") {
                curr->right = new TreeNode(stoi(v[i]));
                q.push(curr->right);
            }

            i++;
        }

        return root;
    }
};