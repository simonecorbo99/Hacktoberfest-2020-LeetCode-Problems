/**
 * Solution to odd-even-linked-list at LeetCode in JAVA
 *
 * author: VishnuRameshbabu
 * ref: https://leetcode.com/problems/odd-even-linked-list/
 */


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
    public ListNode oddEvenList(ListNode head) {
     ListNode eve=new ListNode();
        if(head==null){return head;}
        if(head.next!=null){
            eve=head.next;
        }else{return head;}
        ListNode curr=new ListNode();
        ListNode eve2=new ListNode();
        curr=head;
        eve2=eve;
        if(head.next!=null && head.next.next!=null){           
            try{
        while(curr.next.next!=null){         
            curr.next=curr.next.next;
            curr=curr.next;
            if(eve2.next.next!=null){
                eve2.next=eve2.next.next;
                eve2=eve2.next;
            }else{
eve2.next=null;
                               
            }         
        }
            }
            catch(Exception e){
            if(curr.next==null || curr.next.next==null){
            curr.next=eve;
          
            }
            
        }
        }  
        return head;
    }
}