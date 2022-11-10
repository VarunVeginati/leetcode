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
    
    int getTotalNodes(ListNode* head) {
        int cnt = 0;
        while(head!=NULL) {
            cnt++;
            head = head->next;
        }
        
        return cnt;
    }
    
    ListNode* recurssionReverse(ListNode* head, int k, int cnt) {
        if(head==NULL || cnt<k) return head;
        
        ListNode* dummy = new ListNode();
        dummy->next = head;
        
        ListNode* prev = NULL;
        
        for(int i=0; i<k; i++) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        
        dummy->next->next = recurssionReverse(head, k, cnt-k);
        
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt = getTotalNodes(head);
        
        return recurssionReverse(head, k, cnt);
    }
};