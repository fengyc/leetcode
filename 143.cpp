#include <deque>

using namespace std;

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
    void reorderList(ListNode *head) {
        if (!head) {
            return;
        }
        deque<ListNode *> dq;
        auto p = head->next;
        while (p) {
            dq.push_back(p);
            p = p->next;
        }
        bool fromTail = true;
        p = head;
        while (!dq.empty()) {
            if (fromTail) {
                p->next = dq.back();
                dq.pop_back();
            } else {
                p->next = dq.front();
                dq.pop_front();
            }
            fromTail = !fromTail;
            p = p->next;
        }
        p->next = nullptr;
    }

    void reorderList2(ListNode *head) {
        if (!head) {
            return;
        }
        // split
        auto middle = head;
        auto tail = head;
        while (true) {
            middle = middle->next;
            tail = tail->next;
            if (tail) {
                tail = tail->next;
            }
            if (!tail) {
                break;
            }
        }
        auto p = head;
        while (p->next != middle) {
            p = p->next;
        }
        p->next = nullptr;

        if (middle) {
            // reverse
            tail = middle;
            while (tail->next) {
                auto p = tail->next;
                tail->next = p->next;
                p->next = middle;
                middle = p;
            }
            // merge
            auto p1 = head;
            auto p2 = middle;
            while (p1 && p2) {
                auto tmp = p2->next;
                p2->next = p1->next;
                p1->next = p2;
                p1 = p2->next;
                p2 = tmp;
            }
        }
    }
};

int main() {
    Solution s;

    auto n1 = new ListNode(1);
    auto n2 = new ListNode(2);
    auto n3 = new ListNode(3);
    auto n4 = new ListNode(4);
    auto n5 = new ListNode(5);
//    n1->next = n2;
//    n2->next = n3;
//    n3->next = n4;
//    n4->next = n5;

    s.reorderList2(n1);

    return 0;
}

