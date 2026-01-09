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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).first;
    }
private:
    pair<TreeNode*,int> dfs(TreeNode* node){
        if(node==nullptr){
            return {nullptr,0};
        }

        auto left=dfs(node->left);
        auto right=dfs(node->right);

        int leftDepth=left.second;
        int rightDepth=right.second;

        if(leftDepth>rightDepth){
            return{left.first,leftDepth+1};
        }
        if(rightDepth>leftDepth){
            return{right.first,rightDepth+1};
        }
        return{node,leftDepth+1};
    }
};