/*
 * @lc app=leetcode id=623 lang=cpp
 *
 * [623] Add One Row to Tree
 *
 * https://leetcode.com/problems/add-one-row-to-tree/description/
 *
 * algorithms
 * Medium (54.15%)
 * Likes:    1454
 * Dislikes: 182
 * Total Accepted:    90K
 * Total Submissions: 165.6K
 * Testcase Example:  '[4,2,6,3,1,5]\n1\n2'
 *
 * Given the root of a binary tree and two integers val and depth, add a row of
 * nodes with value val at the given depth depth.
 * 
 * Note that the root node is at depth 1.
 * 
 * The adding rule is:
 * 
 * 
 * Given the integer depth, for each not null tree node cur at the depth depth
 * - 1, create two tree nodes with value val as cur's left subtree root and
 * right subtree root.
 * cur's original left subtree should be the left subtree of the new left
 * subtree root.
 * cur's original right subtree should be the right subtree of the new right
 * subtree root.
 * If depth == 1 that means there is no depth depth - 1 at all, then create a
 * tree node with value val as the new root of the whole original tree, and the
 * original tree is the new root's left subtree.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [4,2,6,3,1,5], val = 1, depth = 2
 * Output: [4,1,1,2,null,null,6,3,1,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [4,2,null,3,1], val = 1, depth = 3
 * Output: [4,2,null,1,1,3,null,null,1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 10^4].
 * The depth of the tree is in the range [1, 10^4].
 * -100 <= Node.val <= 100
 * -10^5 <= val <= 10^5
 * 1 <= depth <= the depth of tree + 1
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
    TreeNode* helper(TreeNode* root, int val, int depth, bool left) {
        if (depth == 1) {
            TreeNode* new_root = new TreeNode(val);
            if (left) {
                new_root->left = root;
            } else {
                new_root->right = root;
            }
            return new_root;
        }
        if (root == nullptr) {
            return root;
        }
        root->left = helper(root->left, val, depth - 1, true);
        root->right = helper(root->right, val, depth - 1, false);
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return helper(root, val, depth, true);
    }
};
// @lc code=end

