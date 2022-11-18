// @lc app=leetcode id=104 lang=cpp
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int depth_left = maxDepth(root->left);
        int depth_right = maxDepth(root->right);
        if (depth_left > depth_right) {
            return 1 + depth_left;
        } else {
            return 1 + depth_right;
        }
    }
};
// @lc code=end