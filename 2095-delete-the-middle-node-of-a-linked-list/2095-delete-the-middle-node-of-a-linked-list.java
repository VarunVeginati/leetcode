/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int getLength(ListNode head) {
        int res = 0;
        while(head!=null) {
            res++;
            head = head.next;
        }
        
        return res;
    }
    
    public ListNode deleteMiddle(ListNode head) {
        ListNode dummy = head;
        
        int n = getLength(head)/2;
        
        if(n==0) return null;
        
        for(int i=0; i<n-1; i++) head = head.next;
        
        head.next = head.next.next;
        
        return dummy;
    }
}