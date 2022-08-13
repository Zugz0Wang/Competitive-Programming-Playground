
//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curr_A = headA;
        while(curr_A != nullptr) {
            ListNode* curr_B = headB;
            while(curr_B != nullptr) {
                if (curr_B == curr_A) { // If same node
                    return curr_A;
                }
                curr_B = curr_B->next;
            }
            curr_A = curr_A->next;
        }
        return nullptr;
    }
};