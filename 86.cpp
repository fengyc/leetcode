
#include <cstdlib>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *tail = head;
        int size = tail ? 1 : 0;
        while (tail && tail->next) {
            tail = tail->next;
            size++;
        }

        ListNode *prev = nullptr;
        ListNode *cur = head;
        while (size--) {
            if (cur->val >= x && cur != tail) {
                tail->next = cur;
                if (prev) {
                    prev->next = cur->next;
                    cur = prev->next;
                } else {
                    head = cur->next;
                    cur = head;
                }
                tail = tail->next;
                tail->next = nullptr;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }

        return head;
    }
};

class Solution2 {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *head1 = nullptr;
        ListNode *tail1 = nullptr;
        ListNode *head2 = nullptr;
        ListNode *tail2 = nullptr;

        ListNode *p = head;
        while (p) {
            if (p->val >= x) {
                if (tail2) {
                    tail2->next = p;
                    tail2 = tail2->next;
                } else {
                    head2 = p;
                    tail2 = p;
                }
                p = p->next;
                tail2->next = nullptr;
            } else {
                if (tail1) {
                    tail1->next = p;
                    tail1 = tail1->next;
                } else {
                    head1 = p;
                    tail1 = p;
                }
                p = p->next;
                tail1->next = nullptr;
            }
        }

        head = head1;
        if (tail1) {
            tail1->next = head2;
        }
        if (!head) {
            head = head2;
        }

        return head;
    }
};

struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode *head1 = NULL;
    struct ListNode *tail1 = NULL;
    struct ListNode *head2 = NULL;
    struct ListNode *tail2 = NULL;
    struct ListNode *p = head;

    while (p) {
        if (p->val >= x) {
            if (tail2) {
                tail2->next = p;
                tail2 = tail2->next;
            } else {
                head2 = p;
                tail2 = p;
            }
            p = p->next;
            tail2->next = NULL;
        } else {
            if (tail1) {
                tail1->next = p;
                tail1 = tail1->next;
            } else {
                head1 = p;
                tail1 = p;
            }
            p = p->next;
            tail1->next = NULL;
        }
    }

    head = head1;
    if (tail1) {
        tail1->next = head2;
    }
    if (!head) {
        head = head2;
    }

    return head;
}


int main() {
    auto l0 = new ListNode(1);
//    auto l1 = new ListNode(4);
//    auto l2 = new ListNode(3);
//    auto l3 = new ListNode(2);
//    auto l4 = new ListNode(5);
//    auto l5 = new ListNode(2);
//    l0->next = l1;
//    l1->next = l2;
//    l2->next = l3;
//    l3->next = l4;
//    l4->next = l5;

    Solution s;
    auto r = s.partition(nullptr, 3);

    Solution2 s2;
    auto r2 = s2.partition(l0, 0);

    return 0;
}