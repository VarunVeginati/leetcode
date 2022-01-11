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
    vector<string> vec;
    
    void dfs(TreeNode* root, string s) {
        if(root==NULL) return;
        
        if(root->left==NULL && root->right==NULL) {
            s = s+to_string(root->val);
            vec.push_back(s);
            return;
        }
        
        dfs(root->left, s+to_string(root->val));
        dfs(root->right, s+to_string(root->val));
    }
    
    int bin_to_dec(string s) {
        int pow = 1;
        int res = 0;
        for(int i=s.length()-1; i>=0; i--) {
            res = res + (((int)s[i]-48)*pow);
            pow=pow*2;
        }
        
        return res;
    }
    
    int sumRootToLeaf(TreeNode* root) {
        dfs(root, "");
        int ans = 0;
        
        for(int i=0; i<vec.size(); i++) {
            ans = ans + bin_to_dec(vec[i]);
        }
        
        return ans;
    }
};