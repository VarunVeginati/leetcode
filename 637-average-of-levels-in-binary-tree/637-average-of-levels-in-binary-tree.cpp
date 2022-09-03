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
    
    void levelOrder(TreeNode* root, int level, long &sum, int &n) {
        if(root==NULL) return;
        
        if(level==0) {
            n++;
            sum += root->val;
        } else {
            levelOrder(root->left, level-1, sum, n);
            levelOrder(root->right, level-1, sum, n);
        }
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        int ht = height(root);
        vector<double> res;
        
        for(int i=0; i<ht; i++) {
            long sum = 0;
            int n = 0;
            levelOrder(root, i, sum, n);
            
            res.push_back((double)sum/(double)n);
        }
        
        return res;
    }
};