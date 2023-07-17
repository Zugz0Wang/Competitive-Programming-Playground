/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
 *
 * https://leetcode.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (59.10%)
 * Likes:    4985
 * Dislikes: 255
 * Total Accepted:    395.3K
 * Total Submissions: 655.7K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The most significant digit comes first and each of their nodes
 * contains a single digit. Add the two numbers and return the sum as a linked
 * list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: l1 = [7,2,4,3], l2 = [5,6,4]
 * Output: [7,8,0,7]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [8,0,7]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: l1 = [0], l2 = [0]
 * Output: [0]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in each linked list is in the range [1, 100].
 * 0 <= Node.val <= 9
 * It is guaranteed that the list represents a number that does not have
 * leading zeros.
 * 
 * 
 * 
 * Follow up: Could you solve it without reversing the input lists?
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
class Solution { // Independently solved (read the follow up)
public:
    void reverse(ListNode** head_ptr) {
        ListNode* next(nullptr);
        ListNode* curr(*head_ptr);
        ListNode* prev(nullptr);
        while (curr != nullptr) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        *head_ptr = prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        reverse(&l1);
        reverse(&l2);
        ListNode* ans(nullptr);
        ListNode** curr_tail(&ans);
        int carry(0);
        while (l1 || l2 || carry > 0) {
            int num1(0);
            if (l1) {
                num1 = l1->val;
                l1 = l1 -> next;
            }
            int num2(0);
            if (l2) {
                num2 = l2 -> val;
                l2 = l2 -> next;
            }
            int sum(num1 + num2 + carry);
            ListNode* insert(new ListNode(sum % 10));
            *curr_tail = insert;
            curr_tail = &(insert->next);
            carry = sum / 10;
        }
        reverse(&ans);
        return ans;
    }
};
// @lc code=end

