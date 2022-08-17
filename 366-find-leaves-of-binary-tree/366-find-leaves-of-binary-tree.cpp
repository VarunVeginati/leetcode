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
    TreeNode* head;
    
    bool isLeaf(TreeNode* root) {
        return root->left==NULL && root->right==NULL;
    }
    
    void dfs(TreeNode* root, vector<int> &vec) {
        if(root==NULL) return;
        
        if(root->left != NULL && isLeaf(root->left)) {
            vec.push_back(root->left->val);
            root->left = NULL;
        }
        
        if(root->right != NULL && isLeaf(root->right)) {
            vec.push_back(root->right->val);
            root->right = NULL;
        }
        
        dfs(root->left, vec);
        dfs(root->right, vec);
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        head = root;
        
        while(!isLeaf(root)) {
            vector<int> vec;
            dfs(head, vec);
            res.push_back(vec);
        }
        
        res.push_back({head->val});
        
        return res;
    }
};