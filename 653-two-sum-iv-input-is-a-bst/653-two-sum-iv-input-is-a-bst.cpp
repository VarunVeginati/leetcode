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
    
    void inorder(TreeNode* root, vector<int> &vec) {
        if(root == NULL) return;
        
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> vec;
        inorder(root, vec);
        
        map<int, int> m;
        
        for(int i=0; i<vec.size(); i++) {
            int target = k-vec[i];
            if(m[target] > 0) return true;
            else
                m[vec[i]]++;
        }
        
        return false;
    }
};