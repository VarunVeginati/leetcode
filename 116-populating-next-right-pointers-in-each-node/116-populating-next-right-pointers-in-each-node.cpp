/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    int height(Node* root) {
        if(root == NULL) return 0;
        
        return height(root->left)+1;
    }
    
    void levelOrder(Node* &root, Node* prev, int level) {
        if(root == NULL) return;
        
        if(level == 1) {
            if(prev != NULL)
                prev->next = root;
            return;
        } else {
            if(prev!=NULL) prev=prev->right;
            levelOrder(root->left, prev, level-1);
            levelOrder(root->right, root->left, level-1);
        }
    }
    
    Node* connect(Node* root) {
        int ht = height(root);
        
        for(int i=1; i<=ht; i++) {
            levelOrder(root, NULL, i);
        }
        
        return root;
    }
};