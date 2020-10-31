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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int k = 0;
        ListNode *ptr = head;
        while(k < n){
            if(ptr->next == NULL){
                if(k==n-1){
                    head = head->next;
                    return head;
                }        
            }    
            ptr = ptr->next;
            k++;
        }
        ListNode* temp = head;
        while(ptr->next != NULL){
            temp = temp->next;
            ptr = ptr->next;
        }
        temp->next = temp->next->next;
        return head;
            
    }
};
