/**
 * Solution to Remove Duplicates from Sorted List II at LeetCode in <language>
 *
 * author: anshul3pathi
 * ref: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii
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


# include <set>
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        set<int> val;
        ListNode *curr = head, *next, *prev;
        if(!head) return nullptr;        
        while(curr->next) {
            next = curr->next;
            if(curr->val == next->val) {
                val.insert(curr->val);
            }
            curr = curr->next;
        }
        curr = head;
        prev = nullptr;
        while(curr) {
            if(curr == head && val.find(curr->val) != val.end()) {
                head = curr->next;
                delete curr;
                curr = head;
            } else if(val.find(curr->val) != val.end() && curr->next) {
                ListNode *toDel = curr;
                curr = curr->next;
                prev->next = curr;
                delete toDel;
            } else if(val.find(curr->val) != val.end() && !curr->next) {
                prev->next = nullptr;
                ListNode *toDel = curr;
                curr = curr->next;
                delete toDel;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};
