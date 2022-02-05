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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* l1 = new ListNode();
        l1 = l1->next;
        
        for(ListNode* list: lists) {
            ListNode* l2 = list;
            ListNode* l3 = new ListNode();
            ListNode* head_l3 = l3;   
            
            while(l1!=NULL || l2!=NULL) {
                if(l1 != NULL && (l2==NULL || l1->val <= l2->val)) {
                    l3->next = l1;
                    l1 = l1->next;
                    l3 = l3->next;
                } else {
                    l3->next = l2;
                    l2 = l2->next;
                    l3 = l3->next;
                }
            }
            l1 = head_l3->next;
        }
        
        return l1;
    }
};