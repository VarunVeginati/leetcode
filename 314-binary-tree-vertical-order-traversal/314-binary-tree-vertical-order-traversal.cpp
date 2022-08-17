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
    int mn = 0;
    int mx = 0;
    map<int,vector<int> > m;
    
    void bfs(TreeNode* root) {
        queue<pair<TreeNode*,int> > q;
        q.push(make_pair(root, 0));
        
        while(!q.empty()) {
            pair<TreeNode*,int> curr = q.front();
            q.pop();
            mn = min(mn, curr.second);
            mx = max(mx, curr.second);
            m[curr.second].push_back(curr.first->val);
            
            if(curr.first->left != NULL) {
                q.push(make_pair(curr.first->left, curr.second-1));
            }
            if(curr.first->right != NULL) {
                q.push(make_pair(curr.first->right, curr.second+1));
            }
        }
    }
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        
        if(root==NULL) return res;
        
        bfs(root);
        
        for(int i=mn; i<=mx; i++) {
            res.push_back(m[i]);
        }
        
        return res;
    }
};