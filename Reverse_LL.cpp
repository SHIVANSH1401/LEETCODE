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
 /*We process the linked list in groups of k nodes. For each group, we first check if k nodes exist,
  then reverse that group and connect it to the previously reversed part. If fewer than k nodes remain, they are left unchanged.*/

class Solution {
public:
    ListNode* findKthNode(ListNode* temp, int k) {
        k--;

        while (temp != NULL && k--) {
            temp = temp->next;
        }

        return temp;
    }

    ListNode* reverse(ListNode* head) {
        ListNode *prev = NULL, *curr = head;

        while (curr) {
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;

        while (temp) {
            ListNode* kthNode = findKthNode(temp, k);

            if (kthNode == NULL) {
                if (prevLast)
                    prevLast->next = temp;
                break;
            }

            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;

            ListNode* newHead = reverse(temp);

            if (temp == head)
                head = newHead;
            else
                prevLast->next = newHead;

            prevLast = temp;
            temp = nextNode;
        }

        return head;
    }
};