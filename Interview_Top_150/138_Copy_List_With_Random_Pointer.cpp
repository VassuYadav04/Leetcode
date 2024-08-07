class Solution {
public:
    Node* copyRandomList(Node* head) {
        for (auto *curr = head; curr; curr = curr->next->next) {
            auto *node = new Node(curr->val);
            node->next = curr->next;
            curr->next = node;
        }

        for (auto *curr = head; curr; curr = curr->next->next) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
        }

        Node dummy(0);
        for (auto *curr = head, *copy_curr = &dummy;
             curr;
             copy_curr = copy_curr->next, curr = curr->next) {
            copy_curr->next = curr->next;
            curr->next = curr->next->next;
        }

        return dummy.next;
    }
};