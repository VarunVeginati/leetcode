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
    
    void inorder(TreeNode* root, vector<TreeNode*> &vec) {
        if(root == NULL) return;
        
        inorder(root->left, vec);
        vec.push_back(root);
        inorder(root->right, vec);
    }
    
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        vector<TreeNode*> vec;
        inorder(root, vec);
        
        for(int i=0; i<vec.size(); i++) {
            if(vec[i] == p && i<vec.size()-1) return vec[i+1];
            else if(vec[i] == p && i>=vec.size()-1) return NULL;
        }
        
        return NULL;
    }
};