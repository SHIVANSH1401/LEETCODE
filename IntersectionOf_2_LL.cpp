/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
 /*We use two pointers starting from the heads of both linked lists.
  When a pointer reaches the end of its list, it starts traversing the other list. 
  This makes both pointers travel the same total distance, so they meet at the intersection node, 
  or both become NULL if no intersection exists.*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL)
            return NULL;

        ListNode *t1 = headA;
        ListNode *t2 = headB;

        while (t1 != t2) {
            t1 = (t1 == NULL) ? headB : t1->next;
            t2 = (t2 == NULL) ? headA : t2->next;
        }

        return t1;
    }
};