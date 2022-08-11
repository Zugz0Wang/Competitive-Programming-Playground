
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* current = head;
        ListNode* check = head;
        int length = 0;
        while(current != nullptr) {
            current = current->next;
            length++;
            int i = 0;
            while (i < length) { // Check if returned to previous node
                if (check == current) {
                    return current;
                }
                check = check->next;
                i++;
            }
            check = head;
        }
        return nullptr;
    }
};