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
    int cnt = 0;
    
    void dfs(TreeNode* root, vector<int> &vec) {
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL) {
            vec[root->val]++;
            int oddCnt = 0;
            for(int i=1; i<=9; i++) {
                if(vec[i]%2!=0) oddCnt++;
            }
            if(oddCnt<=1) cnt++;
            vec[root->val]--;
            return;
        }
        
        vec[root->val]++;
        dfs(root->left, vec);
        dfs(root->right, vec);
        vec[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> vec(10, 0);
        dfs(root, vec);
        return cnt;
    }
};