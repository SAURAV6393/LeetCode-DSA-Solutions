
class Solution {
public:
    int level(TreeNode* root) {
        if(root == NULL) return 0;
        return 1 + max(level(root->left), level(root->right));
    }

    void nthlevel(TreeNode* root, vector<vector<int>>& ans, int curr, int lev) {
        if(root == NULL) return;
        if(curr == lev) {
            ans[lev - 1].push_back(root->val);
            return;
        }

        nthlevel(root->left, ans, curr + 1, lev);
        nthlevel(root->right, ans, curr + 1, lev);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        int n = level(root);
        for(int i = 1; i <= n; i++) {
            ans.push_back(vector<int>());
            nthlevel(root, ans, 1, i);
        }

        return ans;
    }
};
