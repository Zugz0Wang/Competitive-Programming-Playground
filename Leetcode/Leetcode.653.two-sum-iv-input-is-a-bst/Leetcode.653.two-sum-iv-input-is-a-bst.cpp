/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
 *
 * https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
 *
 * algorithms
 * Easy (59.22%)
 * Likes:    4460
 * Dislikes: 215
 * Total Accepted:    358.4K
 * Total Submissions: 603.3K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n9'
 *
 * Given the root of a Binary Search Tree and a target number k, return true if
 * there exist two elements in the BST such that their sum is equal to the
 * given target.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [5,3,6,2,4,null,7], k = 9
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [5,3,6,2,4,null,7], k = 28
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 10^4].
 * -10^4 <= Node.val <= 10^4
 * root is guaranteed to be a valid binary search tree.
 * -10^5 <= k <= 10^5
 * 
 * 
 */

// * Definition for a binary tree node.
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
    int arr[10001];
    int idx = 0;
    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        if (root->left) inorder(root->left);
        arr[idx] = root->val;
        idx++;
        if (root->right) inorder(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        for (int i = 0, j = idx - 1; i < j;) {
            int curr_val = arr[i] + arr[j];
            if (curr_val == k) {
                return true;
            } else if (curr_val < k) {
                i++;
            } else {
                j--;
            }
        }
        return false;
    }
};
// @lc code=end

