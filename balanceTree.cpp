class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> values;
        inorderTraversal(root, values);
        return buildBalancedBST(values, 0, values.size() - 1);
    }
    
private:
    void inorderTraversal(TreeNode* node, vector<int>& values) {
        if (!node) return;
        
        inorderTraversal(node->left, values);
        values.push_back(node->val);
        inorderTraversal(node->right, values);
    }
    
    TreeNode* buildBalancedBST(vector<int>& values, int left, int right) {
        if (left > right) return nullptr;
        
        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(values[mid]);
        
        node->left = buildBalancedBST(values, left, mid - 1);
        node->right = buildBalancedBST(values, mid + 1, right);
        
        return node;
    }
};