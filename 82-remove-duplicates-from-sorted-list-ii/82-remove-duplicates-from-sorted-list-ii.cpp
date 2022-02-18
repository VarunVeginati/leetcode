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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        bool duplicateHead = false;
        
        while(head!=NULL && head->next!=NULL &&
              head->val == head->next->val) {
            duplicateHead = true;
            head = head->next;
        }
        
        if(duplicateHead)
            return deleteDuplicates(head->next);
        
        head->next = deleteDuplicates(head->next);
        
        return head;
    }
};