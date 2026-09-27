class Solution {
public:
    vector<string> ans;
    vector<int> path;

    void dfs(TreeNode* root) {
        if(root == nullptr) {
            return;
        }

        path.push_back(root->val);

        if(root->left == nullptr && root->right == nullptr) {
            string s = "";

            for(int i = 0; i < path.size(); i++) {
                s = s + to_string(path[i]);

                if(i != path.size() - 1) {
                    s = s + "->";
                }
            }

            ans.push_back(s);
        }

        dfs(root->left);
        dfs(root->right);

        path.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root);
        return ans;
    }
};