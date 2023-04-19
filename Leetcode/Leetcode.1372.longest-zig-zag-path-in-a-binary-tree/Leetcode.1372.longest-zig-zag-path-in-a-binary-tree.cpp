/*
 * @lc app=leetcode id=1372 lang=cpp
 *
 * [1372] Longest ZigZag Path in a Binary Tree
 *
 * https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/description/
 *
 * algorithms
 * Medium (59.41%)
 * Likes:    1516
 * Dislikes: 26
 * Total Accepted:    46.5K
 * Total Submissions: 77.1K
 * Testcase Example:  '[1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,1]'
 *
 * You are given the root of a binary tree.
 * 
 * A ZigZag path for a binary tree is defined as follow:
 * 
 * 
 * Choose any node in the binary tree and a direction (right or left).
 * If the current direction is right, move to the right child of the current
 * node; otherwise, move to the left child.
 * Change the direction from right to left or from left to right.
 * Repeat the second and third steps until you can't move in the tree.
 * 
 * 
 * Zigzag length is defined as the number of nodes visited - 1. (A single node
 * has a length of 0).
 * 
 * Return the longest ZigZag path contained in that tree.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,1]
 * Output: 3
 * Explanation: Longest ZigZag path in blue nodes (right -> left -> right).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,1,1,null,1,null,null,1,1,null,1]
 * Output: 4
 * Explanation: Longest ZigZag path in blue nodes (left -> right -> left ->
 * right).
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [1]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 5 * 10^4].
 * 1 <= Node.val <= 100
 * 
 * 
 */

//   Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start

class Solution { // Independently solved
public:
    enum stat {root, left, right};
    int max = 0;
    int helper(TreeNode* root, stat s) {
        int right(0);
        int left(0);
        if (root->right) {
            right = 1 + helper(root->right, stat::right);
        }
        if (root->left) {
            left = 1 + helper(root->left, stat::left);
        }
        if (s == stat::root) {
            if (left > max) {
                max = left;
            }
            if (right > max) {
                max = right;
            }
            return max;
        } else if (s == stat::left) {
            if (left > max) {
                max = left;
            }
            return right;
        } else {
            if (right > max) {
                max = right;
            }
            return left;
        }
        
    }

    int longestZigZag(TreeNode* root) {
        
        return helper(root, stat::root);
    }
};
// @lc code=end

