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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            vector<int> vec;
            
            for(int i=0; i<size; i++) {
                vec.push_back(q.front() == NULL ? -200:q.front()->val);
                
                if(q.front() != NULL) {
                    q.push(q.front()->left);
                    q.push(q.front()->right);
                }
                q.pop();
            }
            
            vector<int> rev = vec;
            reverse(rev.begin(), rev.end());
            if(rev != vec) return false;
        }
        
        return true;
    }
};