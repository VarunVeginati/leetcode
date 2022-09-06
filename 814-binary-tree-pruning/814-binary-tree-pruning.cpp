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
    bool is_leaf(TreeNode* root) {
        return root->left == NULL && root->right == NULL;
    }
    
    bool dfs(TreeNode* &root) {
        if(root == NULL) return false;
        if(is_leaf(root)) {
            if(root->val==0) return false;
            else return true;
        }
        
        bool left = dfs(root->left);
        bool right = dfs(root->right);
        
        if(!left) {
            root->left = NULL;
        }
        if(!right) {
            root->right = NULL;
        }
        
        return root->val==1 || left || right;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        if(dfs(root)) {
            return root;
        } else {
            return NULL;
        }
    }
};