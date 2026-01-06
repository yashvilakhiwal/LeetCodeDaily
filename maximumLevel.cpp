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
    int maxLevelSum(TreeNode* root) {
        if(root==nullptr) return 0;
        queue<TreeNode*>q;
        q.push(root);
        int max_sum=INT_MIN;
        int currentlevel=1;
        int maxLevel=1;
        while(!q.empty()){
            int  level_size=q.size();
            int levelSum=0;
            for(int i=0;i<level_size;i++){
                TreeNode* node=q.front();
                q.pop();
                levelSum+=node->val;
                if(node->left!=nullptr){
                    q.push(node->left);
                }
                if(node->right!=nullptr){
                    q.push(node->right);
                }

            }
            if(levelSum>max_sum){
                max_sum=levelSum;
                maxLevel=currentlevel;
            }
            currentlevel++;
        }
        return maxLevel;

    }
};