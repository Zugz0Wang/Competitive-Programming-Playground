// @lc app=leetcode id=83 lang=cpp
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* prev_node = head;
        ListNode* curr_node = head->next;
        while (curr_node != nullptr) {
           if (prev_node->val == curr_node->val) { // Delete the duplicate node
               prev_node->next = curr_node->next;
               delete curr_node;
           } else {
               prev_node = curr_node;
           }
            curr_node = prev_node->next;
        }
        return head;
    }
};
// @lc code=end