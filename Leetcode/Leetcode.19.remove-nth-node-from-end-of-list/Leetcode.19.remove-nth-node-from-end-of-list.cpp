/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr_node = head;
        ListNode* prev_node = nullptr;
        int length = 0;
        while (curr_node != nullptr) { // Count length of the list
            curr_node = curr_node->next;
            length++;
        }
        curr_node = head;
        while (curr_node != nullptr && length-- > n) {
            prev_node = curr_node;
            curr_node = curr_node->next;
        }
        if (prev_node) {
            if (curr_node) {
                prev_node->next = curr_node->next;
                delete curr_node;
                curr_node = prev_node->next;
            }
        } else {
            head = curr_node -> next;
            delete curr_node;
            curr_node = head;
        }
        return head;
    }
};
// @lc code=end

