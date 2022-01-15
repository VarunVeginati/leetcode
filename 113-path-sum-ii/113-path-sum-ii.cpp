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
    vector<vector<int>> res;
    
    bool is_leaf(TreeNode* root) {
        return root->left==NULL && root->right==NULL;
    }
    
    void dfs(TreeNode* root, vector<int> vec, int targetSum) {
        if(root==NULL) return;
        
        if(targetSum == root->val && is_leaf(root)) {
            vec.push_back(root->val);
            res.push_back(vec);
            vec.pop_back();
            return;
        }
        
        vec.push_back(root->val);
        dfs(root->left, vec, targetSum-root->val);
        dfs(root->right, vec, targetSum-root->val);
        vec.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> vec;
        dfs(root, vec, targetSum);
        
        return res;
    }
};