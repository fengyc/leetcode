/**
 * Definition for singly-linked list.
 */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (!head) {
            return head;
        }

        ListNode *array[100];
        auto count = 0;
        while(head) {
            array[count++] = head;
            head = head->next;
        }

        return array[count >> 1];
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
