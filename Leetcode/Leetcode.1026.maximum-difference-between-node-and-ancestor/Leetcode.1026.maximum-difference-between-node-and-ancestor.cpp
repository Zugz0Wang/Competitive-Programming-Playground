/*
 * @lc app=leetcode id=1026 lang=cpp
 *
 * [1026] Maximum Difference Between Node and Ancestor
 *
 * https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/
 *
 * algorithms
 * Medium (73.33%)
 * Likes:    2853
 * Dislikes: 74
 * Total Accepted:    150.5K
 * Total Submissions: 203.9K
 * Testcase Example:  '[8,3,10,1,6,null,14,null,null,4,7,13]'
 *
 * Given the root of a binary tree, find the maximum value v for which there
 * exist different nodes a and b where v = |a.val - b.val| and a is an ancestor
 * of b.
 * 
 * A node a is an ancestor of b if either: any child of a is equal to b or any
 * child of a is an ancestor of b.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
 * Output: 7
 * Explanation: We have various ancestor-node differences, some of which are
 * given below :
 * |8 - 3| = 5
 * |3 - 7| = 4
 * |8 - 1| = 7
 * |10 - 13| = 3
 * Among all possible differences, the maximum value of 7 is obtained by |8 -
 * 1| = 7.
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,null,2,null,0,3]
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [2, 5000].
 * 0 <= Node.val <= 10^5
 * 
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
    int max(int a, int b) {
        if (a > b) {
            return a;
        } else {
            return b;
        }
    }
    int helper(TreeNode* root, int max_val, int min_val) {
        if (root == nullptr) {
            return max_val - min_val;
        }
        int curr_val = root->val;
        if (curr_val > max_val) {
            max_val = curr_val;
        }
        if (curr_val < min_val) {
            min_val = curr_val;
        }
        
        int left_max = helper(root->left, max_val, min_val);
        int right_max = helper(root->right, max_val, min_val);
        return max(max_val - min_val, max(left_max, right_max));
    } 
    int maxAncestorDiff(TreeNode* root) {
        return helper(root, root->val, root->val);
    }
};
// @lc code=end

