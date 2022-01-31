/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* hv = head;
        Node* dummy = new Node(INT_MIN);
        Node* dummy2 = dummy;
        Node* head2 = head;
        map<Node*, Node*> m;
        
        while(head!=NULL) {
            dummy->next = new Node(head->val);
            m[head] = dummy->next;
            dummy = dummy->next;
            head = head->next;
        }
        
        while(head2!=NULL) {
            if(head2->random != NULL)
                dummy2->next->random = m[head2->random];
            else
                dummy2->next->random = NULL;
            head2 = head2->next;
            dummy2 = dummy2->next;
        }
        
        return m[hv];
    }
};