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
    
    int height(TreeNode* root) {
        if(root == NULL) return 0;
        
        int left = height(root->left);
        int right = height(root->right);
        
        if(left > right) return 1+left;
        else return 1+right;
    }
    
    void current_level(TreeNode* root, vector<int> &vec, int level, bool reverse) {
        if(root == NULL) return;
        if(level == 1) {
            vec.push_back(root->val);
        } else if(level>1) {
            if(reverse) {
                current_level(root->right, vec, level-1, reverse);
                current_level(root->left, vec, level-1, reverse);
            } else {
                current_level(root->left, vec, level-1, reverse);
                current_level(root->right, vec, level-1, reverse);
            }
        }
    }
    
    void level_order(TreeNode* root) {
        int h = height(root);
        for(int i=1; i<=h; i++) {
            bool reverse = false;
            if(i%2==0) reverse = true;
            vector<int> vec;
            current_level(root, vec, i, reverse);
            res.push_back(vec);
        }
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        level_order(root);
        return res; 
    }
};