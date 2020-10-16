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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // if 'l1' & 'l2' both are empty then return nullptr
        if (!l1 && !l2) return nullptr;

        // if 'l1' is empty then return 'l2'
        if (!l1) return l2;

        // if 'l2' is empty then return 'l1'
        if (!l2) return l1;

        // creating a new ListNode 'head'
        ListNode* head = new ListNode();

        // creatting a new ListNode 'curr' and pointing it to 'head'
        ListNode* curr = head;

        // loop through until ANYONE FROM 'l1' AND 'l2' points to nullptr
        while (l1 && l2) {
            int val1 = l1->val;
            int val2 = l2->val;

            // if first Linked List has smaller value then point 'curr' to 'l1'
            if (val1 < val2) {
                curr->val = val1;
                l1 = l1->next;
            }
            // else point 'curr' to 'l2'
            else {
                curr->val = val2;
                l2 = l2->next;
            }

            if (l1 && l2) {
                curr->next = new ListNode();
                curr = curr->next;
            }
        }

        // if 'l1' is empty then point 'curr' to remaining 'l2'
        if (!l1) curr->next = l2;

        // if 'l2' is empty then point 'curr' to remaining 'l1'
        if (!l2) curr->next = l1;

        return head;
    }
};
