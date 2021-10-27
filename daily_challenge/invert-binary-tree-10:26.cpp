class Solution {
public:
    TreeNode* invert(TreeNode* rootNode) {
        if(rootNode == NULL or (rootNode->left == NULL && rootNode->right == NULL)) return rootNode;
        
        rootNode->left = invert(rootNode->left);
        rootNode->right = invert(rootNode->right);
        
        TreeNode* right = rootNode->right;
        rootNode->right = rootNode->left;
        rootNode->left = right;
        
        return rootNode;
    }
    
    TreeNode* invertTree(TreeNode* root) {
        return invert(root);
    }
};