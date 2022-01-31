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
    void print_vec(vector<int> vec) {
        for(int i=0; i<vec.size(); i++) {
            cout << vec[i] << ", "; 
        }
        cout << endl;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0 || inorder.size()==0) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        
        int head = root->val;
        
        vector<int> inorder_left;
        vector<int> inorder_right;
        vector<int> preorder_left;
        vector<int> preorder_right;
        
        int i;
        for(i=0; i<inorder.size(); i++) {
            if(inorder[i] != head) inorder_left.push_back(inorder[i]);
            else break;
        }
        
        for(int j=i+1; j<inorder.size(); j++) {
            inorder_right.push_back(inorder[j]);
        }
        
        for(int j=1; j<inorder_left.size()+1; j++) {
            preorder_left.push_back(preorder[j]);
        }
        
        for(int j=inorder_left.size()+1; j<preorder.size(); j++) {
            preorder_right.push_back(preorder[j]);
        }
        
//         print_vec(inorder_left);
//         print_vec(inorder_right);
        
        root->left = buildTree(preorder_left, inorder_left);
        root->right = buildTree(preorder_right, inorder_right);
        
        return root;
    }
};