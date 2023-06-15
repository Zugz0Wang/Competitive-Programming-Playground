/*
 * @lc app=leetcode id=1161 lang=cpp
 *
 * [1161] Maximum Level Sum of a Binary Tree
 *
 * https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (66.32%)
 * Likes:    2080
 * Dislikes: 73
 * Total Accepted:    136.8K
 * Total Submissions: 206.2K
 * Testcase Example:  '[1,7,0,7,-8,null,null]'
 *
 * Given the root of a binary tree, the level of its root is 1, the level of
 * its children is 2, and so on.
 * 
 * Return the smallest level x such that the sum of all the values of nodes at
 * level x is maximal.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,7,0,7,-8,null,null]
 * Output: 2
 * Explanation: 
 * Level 1 sum = 1.
 * Level 2 sum = 7 + 0 = 7.
 * Level 3 sum = 7 + -8 = -1.
 * So we return the level with the maximum sum which is level 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
 * Output: 2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 10^4].
 * -10^5 <= Node.val <= 10^5
 * 
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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> wait;
        wait.push(root);
        int max_idx(0);
        int max_val(0);
        int level(1);
        while (!wait.empty()) {
            const size_t size = wait.size();
            int level_sum(0);
            for (size_t i(0); i < size; ++i) {
                TreeNode* curr(wait.front());
                wait.pop();
                level_sum += curr -> val;
                if (curr -> left) {
                    wait.push(curr -> left);
                }

                if (curr -> right) {
                    wait.push(curr -> right);
                }
            }
            if (max_idx == 0 || level_sum > max_val) {
                max_val = level_sum;
                max_idx = level;
            }
            ++level;
        }
        return max_idx;
    }
};
// @lc code=end

