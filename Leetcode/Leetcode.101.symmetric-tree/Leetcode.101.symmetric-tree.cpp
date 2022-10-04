// @lc app=leetcode id=101 lang=cpp
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
    bool isSymmetricHelper(TreeNode* left, TreeNode* right) {
        if (left == nullptr || right == nullptr) {
            if (left == right) {
                return true;
            } else {
                return false;
            }
        }
        return (left->val == right->val) && isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        
        return isSymmetricHelper(root->left, root->right);
    }
};
// @lc code=end