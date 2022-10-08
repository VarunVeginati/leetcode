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
    map<TreeNode*, pair<char,int>> m;
    
    void dfs(TreeNode* target, vector<int> &vec, int k) {
        if(k<0 || target==NULL) return;
        
        if(k==0) {
            vec.push_back(target->val);
            return;
        }
        
        dfs(target->left, vec, k-1);
        dfs(target->right, vec, k-1);
    }
    
    int getDistance(TreeNode* root, TreeNode* target) {
        if(root==NULL) return 0;
        
        if(root==target) return 1;
        
        int left = getDistance(root->left, target);
        int right = getDistance(root->right, target);
        
        if(left==0 && right==0) return 0;
        
        if(right == 0) {
            m[root] = make_pair('l', 1+left);
            return 1+left;
        }
        
        m[root] = make_pair('r', 1+right);
        return 1+right;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> vec;
        dfs(target, vec, k);
        
        getDistance(root, target);
        
        for(auto it: m) {
            if(k-(it.second.second-1) == 0) {
                vec.push_back(it.first->val);
            } else if(it.second.first == 'l') {
                dfs(it.first->right, vec, k-(it.second.second-1)-1);
            } else {
                dfs(it.first->left, vec, k-(it.second.second-1)-1);
            }
        }
        
        return vec;
    }
};