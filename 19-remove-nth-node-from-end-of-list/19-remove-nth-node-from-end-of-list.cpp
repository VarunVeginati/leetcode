/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode* dummy = head;
        ListNode* dummy2 = head;
        
        while(dummy != NULL) {
            cnt++;
            dummy = dummy->next;
        }
        
        if(n>=cnt) return head->next;
        
        for(int i=0; i<cnt-n-1; i++) {
            dummy2 = dummy2->next;
        }
        
        if(dummy2->next!=NULL)
            dummy2->next = dummy2->next->next;
        else
            dummy2->next = NULL;
        
        return head;
    }
};