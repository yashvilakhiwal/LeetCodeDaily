class Solution {
public:
    int sumRootToLeaf(TreeNode* root, int cur = 0) {
        if (!root) return 0;
        cur = cur * 2 + root->val;
        if (!root->left && !root->right) return cur;
        return sumRootToLeaf(root->left, cur) + sumRootToLeaf(root->right, cur);
    }
};