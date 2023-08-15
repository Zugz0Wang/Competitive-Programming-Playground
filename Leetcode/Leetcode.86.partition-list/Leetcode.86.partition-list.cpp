/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
 *
 * https://leetcode.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (50.84%)
 * Likes:    5763
 * Dislikes: 658
 * Total Accepted:    473.1K
 * Total Submissions: 896.4K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * Given the head of a linked list and a value x, partition it such that all
 * nodes less than x come before nodes greater than or equal to x.
 * 
 * You should preserve the original relative order of the nodes in each of the
 * two partitions.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,4,3,2,5,2], x = 3
 * Output: [1,2,2,4,3,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [2,1], x = 2
 * Output: [1,2]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is in the range [0, 200].
 * -100 <= Node.val <= 100
 * -200 <= x <= 200
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution { // Independently solved
public:

    ListNode* partition(ListNode* head, int x) {
        ListNode* less(nullptr);
        ListNode* less_tail(nullptr);
        ListNode* more(nullptr);
        ListNode* more_tail(nullptr);
        while (head != nullptr) {
            ListNode** curr(nullptr);
            ListNode** curr_tail(nullptr);
            if (head->val < x) {
                curr = &less;
                curr_tail = &less_tail;
            } else {
                curr = &more;
                curr_tail = &more_tail;
            }
            ListNode*& c(*curr);
            ListNode*& c_t(*curr_tail);
            if (c != nullptr) {
                c_t->next = head;
                c_t = head;
            } else {
                c = head;
                c_t = head;
            }
            head = head->next;
        }
        if (less) {
            less_tail->next = more;
        } else {
            less = more;
        }
        if (more) {
            more_tail->next = nullptr;
        } else {
            less_tail = nullptr;
        }
        return less;
    }
};
// @lc code=end

