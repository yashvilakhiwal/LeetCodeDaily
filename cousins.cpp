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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==nullptr) return false;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int levelSize=q.size();
            bool foundX=0;
            bool foundY=0;
            for(int i=0;i<levelSize;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left && node->right){
                    if((node->left->val==x && node->right->val==y)
                    ||(node->left->val==y && node->right->val==x)){
                        return false;
                    }
                }
                if(node->val==x) foundX=true;
                if(node->val==y) foundY=true;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
                if(foundX && foundY){
                    return true;
                }
                if(foundX || foundY){
                    return false;
                }

            }
            return false;
        }
    
};