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
    int length(ListNode* head) {
        int cnt = 0;
        while(head!=NULL) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    
    bool isPalindrome(ListNode* head) {
        int cnt = length(head);
        // if(cnt==1) return true;
        
        stack<int> st;
        
        for(int i=0; i<cnt/2; i++) {
            st.push(head->val);
            head=head->next;
        }
        
        if(cnt%2!=0) head=head->next;
        
        while(head!=NULL) {
            if(head->val != st.top()) return false;
            
            head = head->next;
            st.pop();
        }
        
        return true;
    }
};