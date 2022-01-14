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
    bool is_leaf_node(TreeNode* root) {
        if(root==NULL) return false;
        return root->left==NULL && root->right==NULL;
    }
    
    int ht(TreeNode* root) {
        if(root==NULL) return 1000000;
        else if(is_leaf_node(root)) return 1;
        else {
            return min(ht(root->left), ht(root->right))+1;
        }
    }
    
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        else return ht(root);
    }
};