/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
 *
 * https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
 *
 * algorithms
 * Easy (56.51%)
 * Likes:    2915
 * Dislikes: 152
 * Total Accepted:    211.6K
 * Total Submissions: 369.6K
 * Testcase Example:  '[4,2,6,1,3]'
 *
 * Given the root of a Binary Search Tree (BST), return the minimum absolute
 * difference between the values of any two different nodes in the tree.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [4,2,6,1,3]
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,0,48,null,null,12,49]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [2, 10^4].
 * 0 <= Node.val <= 10^5
 * 
 * 
 * 
 * Note: This question is the same as 783:
 * https://leetcode.com/problems/minimum-distance-between-bst-nodes/
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution { // Independently solved
public:
    TreeNode* prev = nullptr;
    int min = -1;
    void helper(TreeNode* curr) {
        if (curr == nullptr) {
            return;
        }
        if (curr -> left) {
            helper(curr -> left);
        }
        
        if (prev != nullptr) {
            int diff(curr -> val - prev -> val);
            if (diff < 0) {
                diff = -diff;
            }
            if (min == -1 || diff < min) {
                min = diff;
            }
        }
        prev = curr;

        if (curr -> right) {
            helper(curr -> right);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        helper(root);
        return min;
    }
};
// @lc code=end

