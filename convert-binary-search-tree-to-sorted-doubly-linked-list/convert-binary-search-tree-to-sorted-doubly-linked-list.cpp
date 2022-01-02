/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* first = NULL;
    Node* last = NULL;
    
    void inorder(Node* root) {
        if(root == NULL) return;
        
        inorder(root->left);
        if(last != NULL) {
            last->right=root;
            root->left=last;
        } else {
            first = root;
        }
        last = root;
        inorder(root->right);
    }
    
    Node* treeToDoublyList(Node* root) {
        if(root==NULL) return NULL;
        inorder(root);
        first->left=last;
        last->right=first;
        return first;
    }
};