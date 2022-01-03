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
    Node* lowestCommonAncestor(Node* p, Node * q) {
        map<int,int> hashmap;
        while(p!=NULL) {
            hashmap[p->val]++;
            p=p->parent;
        }
        
        while(q!=NULL) {
            if(hashmap[q->val]>0) return q;
            q = q->parent;
        }
        
        return NULL;
    }
};