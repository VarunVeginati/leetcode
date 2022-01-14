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
    
    void levelOrder(TreeNode* root, int level, vector<int> &vec) {
        if(root==NULL) return;
        
        if(level==1) {
            vec.push_back(root->val);
        } else {
            levelOrder(root->left, level-1, vec);
            levelOrder(root->right, level-1, vec);
        }
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int ht = height(root);
        vector<vector<int>> res;
        
        for(int i=ht; i>=1; i--) {
            vector<int> vec;
            levelOrder(root, i, vec);
            res.push_back(vec);
        }
        
        return res;
    }
};