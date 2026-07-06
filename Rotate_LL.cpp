/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

 We first calculate the length of the linked list and connect the last node to the head,
  making it circular. Then we move len - k steps to find the new tail, break the circle, and return the next node as the new head.
 */

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0)
            return head;

        int len = 1;
        ListNode* tail = head;

        while (tail->next) {
            tail = tail->next;
            len++;
        }

        k %= len;

        if (k == 0)
            return head;

        tail->next = head;

        int cnt = len - k;
        while (cnt--)
            tail = tail->next;

        head = tail->next;
        tail->next = NULL;

        return head;
    }
};