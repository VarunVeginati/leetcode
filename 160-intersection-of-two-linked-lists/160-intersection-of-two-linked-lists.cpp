/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> st;
        
        while(headA!=NULL || headB!=NULL) {
            if(headA!=NULL && st.find(headA) != st.end()) {
                return headA;
            }
            
            if(headA!=NULL)  {
                st.insert(headA);
                headA = headA->next;
            }
            
            if(headB!=NULL && st.find(headB) != st.end()) {
                return headB;
            }
            
            if(headB!=NULL) {
                st.insert(headB);
                headB = headB->next;
            }
        }
        
        return NULL;
    }
};