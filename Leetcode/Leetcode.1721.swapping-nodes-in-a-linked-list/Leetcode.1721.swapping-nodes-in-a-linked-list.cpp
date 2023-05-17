/*
 * @lc app=leetcode id=1721 lang=cpp
 *
 * [1721] Swapping Nodes in a Linked List
 *
 * https://leetcode.com/problems/swapping-nodes-in-a-linked-list/description/
 *
 * algorithms
 * Medium (67.93%)
 * Likes:    3808
 * Dislikes: 130
 * Total Accepted:    213.2K
 * Total Submissions: 317.7K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * You are given the head of a linked list, and an integer k.
 * 
 * Return the head of the linked list after swapping the values of the k^th
 * node from the beginning and the k^th node from the end (the list is
 * 1-indexed).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3,4,5], k = 2
 * Output: [1,4,3,2,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
 * Output: [7,9,6,6,8,7,3,0,9,5]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is n.
 * 1 <= k <= n <= 10^5
 * 0 <= Node.val <= 100
 * 
 * 
 */

//  Definition for singly-linked list.
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
    ListNode* swapNodes(ListNode* head, int k) { // Independently solved. Busy today.
        if (head == nullptr) {
            return head;
        }
        ListNode* curr(head);
        int i(1);
        while (i < k) {
            curr = curr -> next;
            ++i;
        }
        ListNode* prev0(curr);
        ListNode* prev1(head);
        while (curr -> next != nullptr) {
            curr = curr -> next;
            prev1 = prev1 -> next;
        }

        swap(prev0->val, prev1->val);
        return head;
    }
};
// @lc code=end

