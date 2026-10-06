class Solution {
public:
    int levels(TreeNode* root){
        if(root == NULL) return 0;

        return 1 + max(levels(root->left), levels(root->right));
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;

        if(abs(levels(root->left) - levels(root->right)) > 1)
            return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};