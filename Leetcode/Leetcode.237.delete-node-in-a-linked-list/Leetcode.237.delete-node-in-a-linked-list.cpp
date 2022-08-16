/*
 * @lc app=leetcode id=237 lang=cpp
 *
 * [237] Delete Node in a Linked List
 */
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
    void deleteNode(ListNode* node) {
        ListNode* prev_node = nullptr;
        ListNode* curr_node = node;
        if (curr_node == nullptr) { // If empty
            return;
        }
        while (curr_node->next != nullptr) {
            prev_node = curr_node;
            curr_node = curr_node->next;
            prev_node->val = curr_node->val;
        }
        if (prev_node == nullptr) { // If already a tail, not valid
            return;
        }
        prev_node->next = nullptr;
        delete curr_node;
        return;
    }
};
// @lc code=end

