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
    int maxDepthHelper(TreeNode* root) { // Normal edge counting depth
        if (root == nullptr) {
            return 0;
        }
        int left_height = 0;
        if (root->left) {
            left_height = 1 + maxDepthHelper(root->left);
        }
        int right_height = 0;
        if (root->right) {
            right_height = 1 + maxDepthHelper(root->right);
        }
        int sub_height = 0;
        if (left_height > right_height) {
            sub_height = left_height;
        } else {
            sub_height = right_height;
        }
        return sub_height;
    }
    
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return maxDepthHelper(root) + 1;
    }
};
// @lc code=end