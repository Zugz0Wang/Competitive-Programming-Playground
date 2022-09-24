// @lc app=leetcode id=141 lang=cpp
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
// @lc code=start
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* current = head;
        ListNode* check = head;
        int length = 0;
        while(current != nullptr) {
            current = current->next;
            length++;
            int i = 0;
            while (i < length) { // Check if returned to previous node
                if (check == current) {
                    return true;
                }
                check = check->next;
                i++;
            }
            check = head;
        }
        return false;
    }
};
// @lc code=end