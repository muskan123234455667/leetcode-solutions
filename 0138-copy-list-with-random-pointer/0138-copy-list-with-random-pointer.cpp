class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;

        // Step 1: Create copy after every original node
        Node* curr = head;

        while (curr != NULL) {
            Node* copy = new Node(curr->val);

            copy->next = curr->next;
            curr->next = copy;

            curr = copy->next;
        }

        // Step 2: Set random pointers
        curr = head;

        while (curr != NULL) {
            if (curr->random != NULL) {
                curr->next->random = curr->random->next;
            }

            curr = curr->next->next;
        }

        // Step 3: Separate original and copied list
        curr = head;
        Node* copyHead = head->next;

        while (curr != NULL) {
            Node* copy = curr->next;

            curr->next = copy->next;

            if (copy->next != NULL) {
                copy->next = copy->next->next;
            }

            curr = curr->next;
        }

        return copyHead;
    }
};