/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* getParent(Node* node) {
        while(node->parent!=NULL)
            node = node->parent;
        
        return node;
    }
    
    void getInorder(Node* root, vector<int> &vec) {
        if(root==NULL) return;
        
        getInorder(root->left, vec);
        vec.push_back(root->val);
        getInorder(root->right, vec);
    }
    
    Node* inorderSuccessor(Node* node) {
        Node* root = getParent(node);
        
        vector<int> vec;
        getInorder(root, vec);
        
        int resVal = INT_MIN;
        
        for(int i=0; i<vec.size()-1; i++) {
            if(node->val == vec[i])
                resVal = vec[i+1];
        }
        
        if(resVal==INT_MIN) return NULL;
        
        while(root->val != resVal) {
            if(root->val > resVal)
                root = root->left;
            else
                root = root->right;
        }
        
        return root;
    }
};