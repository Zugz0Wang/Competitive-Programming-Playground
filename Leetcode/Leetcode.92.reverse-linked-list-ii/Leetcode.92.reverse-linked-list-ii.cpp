/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (45.19%)
 * Likes:    7714
 * Dislikes: 336
 * Total Accepted:    559.9K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * Given the head of a singly linked list and two integers left and right where
 * left <= right, reverse the nodes of the list from position left to position
 * right, and return the reversed list.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3,4,5], left = 2, right = 4
 * Output: [1,4,3,2,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [5], left = 1, right = 1
 * Output: [5]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is n.
 * 1 <= n <= 500
 * -500 <= Node.val <= 500
 * 1 <= left <= right <= n
 * 
 * 
 * 
 * Follow up: Could you do it in one pass?
 */
#include <vector>
using namespace std;
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* curr_node = head;
        ListNode* prev_node = nullptr;
        ListNode* prev_node_k = nullptr;

        int i = 1;
        while (curr_node && i < left) {
            prev_node_k = curr_node; // Find the first node before the reverse group, nullptr if at head
            curr_node = curr_node->next;
            i++;
        }
        const int kLength = right - left + 1;

        ListNode* reverse_head = curr_node;
        int j = 0;
        while (curr_node && j < kLength) {
            ListNode* next_node = curr_node->next;
            if (prev_node) {
                curr_node->next = prev_node;
            }
            prev_node = curr_node;
            curr_node = next_node;
            j++;
        }

        reverse_head->next = curr_node;
        if (prev_node_k) {
            prev_node_k->next = prev_node;
        } else {
            head = prev_node;
        }
        return head;
    }
};
// @lc code=end

