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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = new ListNode();
        ListNode* res = head;
        
        while(l1!=NULL && l2!=NULL) {
            int sum = l1->val+l2->val+carry;
            l1=l1->next;
            l2=l2->next;
            carry = 0;
            if(sum>=10) {
                carry++;
                sum = sum%10;
            }
            head->next = new ListNode(sum);
            head = head->next;
        }
        
        while(l1!=NULL) {
            int sum = l1->val+carry;
            l1=l1->next;
            carry = 0;
            if(sum>=10) {
                carry++;
                sum = sum%10;
            }
            head->next = new ListNode(sum);
            head = head->next;
        }
        
        while(l2!=NULL) {
            int sum = l2->val+carry;
            l2=l2->next;
            carry = 0;
            if(sum>=10) {
                carry++;
                sum = sum%10;
            }
            head->next = new ListNode(sum);
            head = head->next;
        }
        
        if(carry==1) head->next = new ListNode(carry);
        
        return res->next;
    }
};