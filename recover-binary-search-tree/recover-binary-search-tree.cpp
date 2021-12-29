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
    vector<int> vec;
    
    void get_all_values(TreeNode* root) {
        if(root == NULL) return;
        
        vec.push_back(root->val);
        get_all_values(root->left);
        get_all_values(root->right);
    }
    
    void recover(TreeNode* &root) {
        if(root==NULL) return;
        
        recover(root->left);
        root->val = vec.back();
        vec.pop_back();
        recover(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        get_all_values(root);
        sort(vec.begin(), vec.end());
        reverse(vec.begin(), vec.end());
        recover(root);
    }
};