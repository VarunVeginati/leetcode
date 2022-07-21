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
    pair<ListNode*,ListNode*> reverse(ListNode* dummy, int cnt) {
        int i = 0;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(dummy != NULL && i<cnt) {
            next = dummy->next;
            dummy->next = prev;
            prev = dummy;
            dummy = next;
            i++;
        }
        return make_pair(prev,next);
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* dummy2 = dummy;
        
        for(int i=1; i<left; i++) {
            dummy=dummy->next;
        }
        
        pair<ListNode*,ListNode*> updatedList = reverse(dummy->next, right-left+1);
        
        dummy->next = updatedList.first;
        
        while(dummy->next!=NULL)
            dummy=dummy->next;
        
        dummy->next = updatedList.second;
        
        return dummy2->next;
    }
};