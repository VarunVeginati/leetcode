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
    void get_all_elements(TreeNode* root, vector<int> &vec) {
        if(root == NULL) return;
        
        get_all_elements(root->left, vec);
        vec.push_back(root->val);
        get_all_elements(root->right, vec);
    }
    
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> vec1;
        vector<int> vec2;
        get_all_elements(root1, vec1);
        get_all_elements(root2, vec2);
        
        vector<int> vec;
        int l1=0;
        int l2=0;
        
        while(vec.size()<(vec1.size()+vec2.size())) {
            if(l1<vec1.size() && l2<vec2.size()) {
                if(vec1[l1]<vec2[l2]) {
                    vec.push_back(vec1[l1]);
                    l1++;
                } else {
                    vec.push_back(vec2[l2]);
                    l2++;
                }
            } else if(l1>=vec1.size()) {
                vec.push_back(vec2[l2]);
                l2++;
            } else {
                vec.push_back(vec1[l1]);
                l1++;
            }
        }
        
        return vec;
    }
};