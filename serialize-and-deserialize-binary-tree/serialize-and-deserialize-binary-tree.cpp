/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        string s = to_string(root->val);
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            
            for(int i=0; i<size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                
                TreeNode* left = curr->left;
                TreeNode* right = curr->right;
                
                if(left==NULL) s+=",n";
                if(left!=NULL) {
                    s+=","+to_string(left->val);
                    q.push(left);
                }
                if(right==NULL) s+=",n";
                if(right!=NULL) {
                    s+=","+to_string(right->val);
                    q.push(right);
                }
            }
        }
        
        return s;
    }
    
    vector<int> unfoldString(string s) {
        int val=0;
        bool negative = false;
        vector<int> res;
        
        for(int i=0; i<s.length(); i++) {
            if(s[i]==',') {
                if(negative) val = -1*val;
                res.push_back(val);
                negative=false;
                val = 0;
            } else if(s[i]=='n') {
                res.push_back(-1001);
                i++;
            } else if(s[i]=='-') {
                negative = true;
            } else {
                val = (val*10)+(s[i]-'0');
            }
        }
        
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length()==0) return NULL;
        vector<int> nodeVals = unfoldString(data);
        TreeNode* root = new TreeNode(nodeVals[0]);
        TreeNode* res = root;
        int idx = 1;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            
            for(int i=0; i<size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                
                if(idx<nodeVals.size()) {
                    curr->left = nodeVals[idx]==-1001 ? NULL:new TreeNode(nodeVals[idx]);
                    if(nodeVals[idx] != -1001)
                        q.push(curr->left);
                    idx++;
                }
                if(idx<nodeVals.size()) {
                    curr->right = nodeVals[idx]==-1001 ? NULL:new TreeNode(nodeVals[idx]);
                    if(nodeVals[idx] != -1001)
                        q.push(curr->right);
                    idx++;
                }
            }
        }
        
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));