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
    
    TreeNode* flattenTree(TreeNode* root) {
        if(root == NULL) return NULL;
        
        if(root->left==NULL && root->right==NULL)
            return root;
        
        TreeNode* left = flattenTree(root->left);
        TreeNode* right = flattenTree(root->right);
        
        if(left!=NULL) {
            left->right=root->right;
            root->right = root->left;
            root->left = NULL;
        }
        
        return right == NULL ? left:right;
    }
    
    void flatten(TreeNode* root) {
        flattenTree(root);
    }
};