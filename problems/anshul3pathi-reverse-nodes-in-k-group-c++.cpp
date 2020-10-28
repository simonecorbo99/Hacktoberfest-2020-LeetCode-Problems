/**
 * Solution to <problem-name> at LeetCode in <language>
 *
 * author: anshul3pathi
 * ref: https://leetcode.com/problems/reverse-nodes-in-k-group
 */


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
ListNode *reverse(ListNode *begin, ListNode *end) {
    ListNode *prev = begin;
    ListNode *curr = prev->next;
    prev->next = nullptr;
    while(prev != end) {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *end = head, *newHead, *curr;
        curr = head;
        int i = 1;
        while(i < k && curr->next) {
            curr = curr->next;
            i++;
        }
        if(i < k) return head;
        else if(curr->next) {
            ListNode *next = curr->next;
            newHead = reverse(head, curr);
            end->next = reverseKGroup(next, k);
        } else {
            newHead = reverse(head, curr);
            end->next = nullptr;
        }
        return newHead;
    }
};