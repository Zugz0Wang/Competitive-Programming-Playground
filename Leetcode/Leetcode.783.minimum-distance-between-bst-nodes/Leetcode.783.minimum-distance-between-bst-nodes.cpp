/*
 * @lc app=leetcode id=783 lang=cpp
 *
 * [783] Minimum Distance Between BST Nodes
 *
 * https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/
 *
 * algorithms
 * Easy (56.54%)
 * Likes:    2071
 * Dislikes: 342
 * Total Accepted:    146.7K
 * Total Submissions: 257K
 * Testcase Example:  '[4,2,6,1,3]'
 *
 * Given the root of a Binary Search Tree (BST), return the minimum difference
 * between the values of any two different nodes in the tree.
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
 * The number of nodes in the tree is in the range [2, 100].
 * 0 <= Node.val <= 10^5
 * 
 * 
 * 
 * Note: This question is the same as 530:
 * https://leetcode.com/problems/minimum-absolute-difference-in-bst/
 * 
 */

//  Definition for a binary tree node.
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
    int prev = -1;
    int curr = -1;
    int min = -1;

    int abs(int a) {
        return a >= 0 ? a : -a;
    }
    void traverse(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        if (root->left) {
            traverse(root->left);
        }
        prev = curr;
        curr = root->val;
        if (prev >= 0) {
            int diff = abs(prev - curr);
            if (diff < min || min == -1) {
                min = diff;
            }
        }
        if (root->right) {
            traverse(root->right);
        }

    }
    int minDiffInBST(TreeNode* root) {
        traverse(root);
        return min;
    }
};
// @lc code=end

