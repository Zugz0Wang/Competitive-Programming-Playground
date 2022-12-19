/*
 * @lc app=leetcode id=1339 lang=cpp
 *
 * [1339] Maximum Product of Splitted Binary Tree
 *
 * https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/
 *
 * algorithms
 * Medium (43.05%)
 * Likes:    1565
 * Dislikes: 68
 * Total Accepted:    66.6K
 * Total Submissions: 152.5K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * Given the root of a binary tree, split the binary tree into two subtrees by
 * removing one edge such that the product of the sums of the subtrees is
 * maximized.
 * 
 * Return the maximum product of the sums of the two subtrees. Since the answer
 * may be too large, return it modulo 10^9 + 7.
 * 
 * Note that you need to maximize the answer before taking the mod and not
 * after taking it.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,2,3,4,5,6]
 * Output: 110
 * Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10.
 * Their product is 110 (11*10)
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,null,2,3,4,null,null,5,6]
 * Output: 90
 * Explanation: Remove the red edge and get 2 binary trees with sum 15 and
 * 6.Their product is 90 (15*6)
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [2, 5 * 10^4].
 * 1 <= Node.val <= 10^4
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
    int total = 0;
    long long result = 0;
    const int kMod = (int)1e9 + 7;
    int sum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return root->val + sum(root->left) + sum(root->right);
    }

    int helper(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
       
        int left = helper(root->left);
        int right = helper(root->right);
        long long sum = (root->val + left + right);
        long long res = (sum * (total - sum));
        if (res > result) {
            result = res;
        }
        return sum;
    }
    int maxProduct(TreeNode* root) {
        total = sum(root);
        helper(root);
        return result % kMod;
    }
};
// @lc code=end

