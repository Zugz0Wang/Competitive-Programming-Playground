/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
 *
 * https://leetcode.com/problems/odd-even-linked-list/description/
 *
 * algorithms
 * Medium (59.93%)
 * Likes:    6563
 * Dislikes: 401
 * Total Accepted:    616K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given the head of a singly linked list, group all the nodes with odd indices
 * together followed by the nodes with even indices, and return the reordered
 * list.
 * 
 * The first node is considered odd, and the second node is even, and so on.
 * 
 * Note that the relative order inside both the even and odd groups should
 * remain as it was in the input.
 * 
 * You must solve the problem in O(1) extra space complexity and O(n) time
 * complexity.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3,4,5]
 * Output: [1,3,5,2,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [2,1,3,5,6,4,7]
 * Output: [2,3,6,7,1,5,4]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the linked list is in the range [0, 10^4].
 * -10^6 <= Node.val <= 10^6
 * 
 * 
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* headEven = nullptr;
        ListNode* tailEven = nullptr;
        ListNode* headOdd = nullptr;
        ListNode* tailOdd = nullptr;
        ListNode* curr = head;
        bool even = true;
        while (curr != nullptr) {
            if (even) {
                if (headEven != nullptr) {
                    tailEven->next = curr;
                    tailEven = curr;
                } else {
                    headEven = curr;
                    tailEven = curr;
                }
            } else {
                if (headOdd != nullptr) {
                    tailOdd->next = curr;
                    tailOdd = curr;
                } else {
                    headOdd = curr;
                    tailOdd = curr;
                }
            }
            curr = curr->next;
            even = !even;
        }
        if (tailEven != nullptr) {
            tailEven->next = headOdd;
        }
        if (tailOdd != nullptr) {
            tailOdd->next = nullptr;
        }
        return headEven;
    }
};
// @lc code=end

