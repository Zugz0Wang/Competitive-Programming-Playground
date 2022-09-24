// @lc app=leetcode id=203 lang=cpp
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* curr_node = head;
        ListNode* prev_node = nullptr;
        while (curr_node != nullptr) {
            if (curr_node->val == val) {
                curr_node = curr_node->next;
                if (prev_node != nullptr) { // deleting node
                    delete prev_node->next;
                    prev_node->next = curr_node;
                } else {
                    delete head;
                    head = curr_node;
                }
            } else {
                prev_node = curr_node;
                curr_node = curr_node->next;
            }
        }
        return head;
    }
};
// @lc code=end