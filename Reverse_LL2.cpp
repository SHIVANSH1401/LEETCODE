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
 /*We use three pointers: prev, curr, and front. For each node, we store the next node, reverse the current node's link, and move all pointers one step forward. When the traversal ends, prev points to the new head of the reversed list.*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *curr = head;

        while (curr) {
            ListNode *front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        return prev;
    }
};