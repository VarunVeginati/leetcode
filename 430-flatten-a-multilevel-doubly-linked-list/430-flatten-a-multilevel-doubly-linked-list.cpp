/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* startingNode = head;
        
        while(head!=NULL) {
            if(head->child == NULL) head = head->next;
            else {
                Node* next = head->next;
                Node* childNode = flatten(head->child);
                head->child = NULL;
                head->next = childNode;
                childNode->prev = head;
                while(head->next != NULL) head = head->next;
                head->next = next;
                if(next!=NULL) next->prev = head;
            }
        }
        
        return startingNode;
    }
};