#include <stdlib.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) {
            return NULL;
        }
        int len = 1;
        auto tail = head;
        while (tail->next) {
            len++;
            tail = tail->next;
        }
        k = k % len;
        tail->next = head;
        for (int i = 0; i < len - k; i++) {
            tail = head;
            head = head->next;
        }
        tail->next = NULL;
        return head;
    }
};

int main() {
    Solution s;

    auto *n1 = new ListNode(1);
    auto *n2 = new ListNode(2);
    auto *n3 = new ListNode(3);
    auto *n4 = new ListNode(4);
    auto *n5 = new ListNode(5);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    auto r = s.rotateRight(n1, 7);

    return 0;
}