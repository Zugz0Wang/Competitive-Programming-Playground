/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
 *
 * algorithms
 * Medium (56.68%)
 * Likes:    5075
 * Dislikes: 119
 * Total Accepted:    393.8K
 * Total Submissions: 694.3K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given the head of a singly linked list where elements are sorted in
 * ascending order, convert it to a height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [-10,-3,0,5,9]
 * Output: [0,-3,9,-10,null,5]
 * Explanation: One possible answer is [0,-3,9,-10,null,5], which represents
 * the shown height balanced BST.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = []
 * Output: []
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in head is in the range [0, 2 * 10^4].
 * -10^5 <= Node.val <= 10^5
 * 
 * 
 */

//   Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


 // Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <vector>
using namespace std;
// @lc code=start

class Solution { // Original
public:
    TreeNode* helper(vector<int>& v, int head, int tail) {
        if (head >= tail) {
            return nullptr;
        }
        int mid_idx = (head + tail) / 2;
        int mid_val = v.at(mid_idx);
        return new TreeNode(mid_val, helper(v, head, mid_idx), helper(v, mid_idx + 1, tail));
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v;
        while (head != nullptr) {
            v.push_back(head->val);
            head = head -> next;
        }
        return helper(v, 0, v.size());
    }
};

// @lc code=end

