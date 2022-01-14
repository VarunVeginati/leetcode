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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> vec;
        queue<TreeNode*> q;
        if(root==NULL) return vec;
        q.push(root);
        
        while(!q.empty()) {
            int q_size = q.size();
            
            for(int i=0; i<q_size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if(i==q_size-1) vec.push_back(node->val);
                
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
            }
        }
        
        return vec;
    }
};