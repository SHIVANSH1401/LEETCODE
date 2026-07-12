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
/*We move the fast pointer n nodes ahead of the slow pointer. 
Then both pointers move together until fast reaches the last node.
 At that point, slow is just before the node to be deleted, so we remove it by updating the links.*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        for (int i = 0; i < n; i++)
            fast = fast->next;

        if (fast == NULL)
            return head->next;

        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        return head;
    }
};