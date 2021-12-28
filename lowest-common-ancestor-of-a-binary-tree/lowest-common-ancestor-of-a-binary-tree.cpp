/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans = NULL;
    
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return false;
        
        int left = dfs(root->left, p, q) ? 1:0;
        int right = dfs(root->right, p, q) ? 1:0;
        int mid = (root==p || root==q) ? 1:0;
        
        if(mid+right+left >= 2) {
            ans = root;
        }
        
        return mid+left+right>0;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root,p,q);
        return ans;
    }
};