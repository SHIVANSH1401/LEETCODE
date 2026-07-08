/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
/*We first insert a copy of every node next to its original node. 
Then we connect the copied nodes' random pointers using the original nodes' random pointers.
 Finally, we separate the original and copied nodes to obtain the deep copied linked list.*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;

        Node* temp = head;

        // Step 1: Insert copied nodes after each original node
        while (temp) {
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = copy->next;
        }

        // Step 2: Connect random pointers
        temp = head;
        while (temp) {
            if (temp->random)
                temp->next->random = temp->random->next;

            temp = temp->next->next;
        }

        // Step 3: Separate original and copied lists
        temp = head;
        Node* dummy = new Node(0);
        Node* copy = dummy;

        while (temp) {
            copy->next = temp->next;
            temp->next = temp->next->next;

            copy = copy->next;
            temp = temp->next;
        }

        return dummy->next;
    }
};