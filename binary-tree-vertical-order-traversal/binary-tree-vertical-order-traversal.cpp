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
    vector<vector<int> > vec;
    
    void build_vector(TreeNode* root, int i, int level) {
        if(root == NULL) return;
        
        vec.push_back({i, root->val, level});
        build_vector(root->left, i-1, level+1);
        build_vector(root->right, i+1, level+1);
    }
    
    static bool comp(pair<int, int> a, pair<int,int> b) {
        return a.second < b.second;
    }
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(root == NULL) return {};
        build_vector(root, 0, 0);
        int min_offset = INT_MAX;
        int max_offset = INT_MIN;
        
        for(int i=0; i<vec.size(); i++) {
            min_offset = min(min_offset, vec[i][0]);
            max_offset = max(max_offset, vec[i][0]);
        }
        
        vector<vector<pair<int, int> >> res(max_offset-min_offset+1);
        
        if(min_offset < 0) min_offset = min_offset*-1;
        
        for(int i=0; i<vec.size(); i++) {
            res[vec[i][0]+min_offset].push_back(make_pair(vec[i][1], vec[i][2]));
        }
        
        vector<vector<int>> out(res.size());
        
        for(int i=0; i<res.size(); i++) {
            sort(res[i].begin(), res[i].end(), comp);
            for(int j=0; j<res[i].size(); j++) {
                out[i].push_back(res[i][j].first);
            }
        }
        
        return out;
    }
};