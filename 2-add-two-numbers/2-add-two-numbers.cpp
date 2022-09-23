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
        ListNode* newNode = new ListNode();
        ListNode* dummy = newNode;
        int carry = 0;
        
        while(l1!=NULL && l2!=NULL) {
            int a = l1->val + l2->val+carry;
            l1 = l1->next, l2=l2->next;
            
            newNode->next = new ListNode(a%10);
            newNode = newNode->next;
            carry = a>=10;
        }
        
        while(l1!=NULL) {
            int a = l1->val + carry;
            l1 = l1->next;
            
            newNode->next = new ListNode(a%10);
            newNode = newNode->next;
            carry = a>=10;
        }
        
        while(l2!=NULL) {
            int a = l2->val + carry;
            l2 = l2->next;
            
            newNode->next = new ListNode(a%10);
            newNode = newNode->next;
            carry = a>=10;
        }
        
        if(carry>0) newNode->next = new ListNode(carry);
        
        
        return dummy->next;
    }
};