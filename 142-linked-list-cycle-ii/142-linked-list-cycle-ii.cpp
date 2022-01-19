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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode* dummy = head;
        ListNode* slow = head;
        ListNode* fast = head;
        
        slow = slow->next;
        if(slow==NULL) return NULL;
        fast = fast->next->next;
        if(fast==NULL) return NULL;
        int i=0;
        
        while(i<100 && slow!=fast) {
            slow = slow->next;
            if(slow==NULL) return NULL;
            if(fast->next==NULL) return NULL;
            fast = fast->next->next;
            if(fast==NULL) return NULL;
        }
        if(slow!=fast) return NULL;
        
        while(dummy!=slow) {
            dummy = dummy->next;
            slow = slow->next;
        }
        
        return slow;
    }
};