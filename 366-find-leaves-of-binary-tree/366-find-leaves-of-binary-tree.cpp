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
    map<int,vector<int>> m;
    
    bool isLeaf(TreeNode* root) {
        return root->left==NULL && root->right==NULL;
    }
    
    int height(TreeNode* root) {
        if(root==NULL) return 0;
        if(isLeaf(root)) {
            m[0].push_back(root->val);
            return 0;
        }
        
        int left = height(root->left);
        int right = height(root->right);
        
        int h = 1+max(left,right);
        m[h].push_back(root->val);
        return h;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        int h = height(root);
        vector<vector<int>> res;
        
        for(int i=0; i<=h; i++) {
            res.push_back(m[i]);
        }
        
        return res;
    }
};