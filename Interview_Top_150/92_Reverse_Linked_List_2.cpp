class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy{0};
        dummy.next = head;

        auto *prev = &dummy;

        for (int i = 0; i < m - 1; ++i) {
            prev = prev->next;
        }

        auto *head2 = prev;

        prev = prev->next;
        auto *cur = prev->next;

        for (int i = m; i < n; ++i) {
            prev->next = cur->next;
            cur->next = head2->next;
            head2->next = cur;
            cur = prev->next;
        }

        return dummy.next;
    }
};