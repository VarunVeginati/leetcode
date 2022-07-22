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
    ListNode* partition(ListNode* head, int x) {
        ListNode* list1 = new ListNode();
        ListNode* list2 = new ListNode();
        ListNode* dummy = list1;
        ListNode* dummy2 = list2;
        
        while(head!=NULL) {
            if(head->val<x) {
                list1->next = new ListNode(head->val);
                list1 = list1->next;
            } else {
                list2->next = new ListNode(head->val);
                list2 = list2->next;
            }
            head = head->next;
        }
        
        list1->next = dummy2->next;
        
        return dummy->next;
    }
};