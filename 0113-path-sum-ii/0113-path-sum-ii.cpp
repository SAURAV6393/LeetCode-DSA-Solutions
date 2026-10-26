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
    void dfs(TreeNode* root, int target, vector<int>& path, vector<vector<int>>& ans) {
        if(!root) return;

        path.push_back(root->val);
        target -= root->val;

        if(!root->left && !root->right && target == 0) ans.push_back(path);

        dfs(root->left, target, path, ans);
        dfs(root->right, target, path, ans);

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(root, targetSum, path, ans);
        return ans;
    }
};
