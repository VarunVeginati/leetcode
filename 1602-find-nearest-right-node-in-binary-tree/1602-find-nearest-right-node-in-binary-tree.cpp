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
    vector<int> vec;
    
    int height(TreeNode* root, TreeNode* u) {
        if(root==NULL) return INT_MIN;
        else if(root == u) return 1;
        
        return 1+max(height(root->left, u),height(root->right, u));
    }
    
    void level_order(TreeNode* root, int level) {
        if(root==NULL) return;
        
        if(level == 1) {
            vec.push_back(root->val);
        } else {
            level_order(root->left, level-1);
            level_order(root->right, level-1);
        }
    }
    
    TreeNode* find(TreeNode* root, int val) {
        if(root == NULL) return NULL;
        
        if(root->val == val) return root;
        
        TreeNode* left = find(root->left, val);
        TreeNode* right = find(root->right, val);
        
        return left==NULL?right:left;
    }
    
    void print_vec(vector<int> vec) {
        for(int i=0; i<vec.size(); i++) {
            cout << vec[i] << ", ";
        }
        
        cout << endl;
    }
    
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        level_order(root, height(root, u));
        int i;
        
        for(i=0; i<vec.size(); i++) {
            if(vec[i]==u->val)
                break;
        }
        
        if(i==vec.size()-1) return NULL;
        
        int a = vec[i+1];
        
        return find(root, a);
    }
};