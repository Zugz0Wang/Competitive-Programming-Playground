/*
 * @lc app=leetcode id=938 lang=cpp
 *
 * [938] Range Sum of BST
 *
 * https://leetcode.com/problems/range-sum-of-bst/description/
 *
 * algorithms
 * Easy (85.27%)
 * Likes:    4850
 * Dislikes: 340
 * Total Accepted:    689.9K
 * Total Submissions: 807.8K
 * Testcase Example:  '[10,5,15,3,7,null,18]\n7\n15'
 *
 * Given the root node of a binary search tree and two integers low and high,
 * return the sum of values of all nodes with a value in the inclusive range
 * [low, high].
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
 * Output: 32
 * Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 =
 * 32.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
 * Output: 23
 * Explanation: Nodes 6, 7, and 10 are in the range [6, 10]. 6 + 7 + 10 =
 * 23.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 2 * 10^4].
 * 1 <= Node.val <= 10^5
 * 1 <= low <= high <= 10^5
 * All Node.val are unique.
 * 
 * 
 */

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start

class Solution {
public:
    int helper(TreeNode* root, int low, int high, int lower, int higher) {
        if (root == nullptr || lower > high || higher <= low) {
            return 0;
        }
        int curr_val = root->val;
        int sum = 0;
        if (curr_val <= high && curr_val >= low) {
            sum += curr_val;
        }
        if (root->left != nullptr && curr_val > low) {
            sum += helper(root->left, low, high, lower, curr_val);
        }
        if (root->right != nullptr && curr_val < high) {
            sum += helper(root->right, low, high, curr_val + 1, higher);
        }
        return sum;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        return helper(root, low, high, 0, 100000);
    }
};
// @lc code=end

