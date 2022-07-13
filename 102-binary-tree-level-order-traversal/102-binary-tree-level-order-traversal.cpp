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
    int height(TreeNode* root) {
        if(root==NULL) return 0;
        
        int left = height(root->left);
        int right = height(root->right);
        
        return max(left,right)+1;
    }
    
    void lvlOrder(TreeNode* root, vector<int> &vec, int level) {
        if(root==NULL) return;
        if(level==0) {
            vec.push_back(root->val);
        } else {
            lvlOrder(root->left, vec, level-1);
            lvlOrder(root->right, vec, level-1);
        }
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        int ht = height(root);
        vector<vector<int>> res;
        
        for(int i=0; i<ht; i++) {
            vector<int> vec;
            lvlOrder(root, vec, i);
            res.push_back(vec);
        }
        
        return res;
    }
};