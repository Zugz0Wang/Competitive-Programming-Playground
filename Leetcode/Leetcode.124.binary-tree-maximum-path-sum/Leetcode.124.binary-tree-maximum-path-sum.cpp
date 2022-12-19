// @lc app=leetcode id=124 lang=cpp
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
    int maxRootPathSumHelper(TreeNode* root, int& max_sum, bool& start) {
        if (root == nullptr) return 0;
        int left_root_path_max = maxRootPathSumHelper(root->left, max_sum, start);
        int right_root_path_max = maxRootPathSumHelper(root->right, max_sum, start);
        int path_sum = left_root_path_max + right_root_path_max + root->val;
        if (start) {
            if (path_sum > max_sum) {
                max_sum = path_sum;
            }
        } else {
            max_sum = path_sum;
            start = true;
        }
        
        int to_return = 0; // If negative, no need for its parent to go down this road
        
        if (root->val > to_return) {
            to_return = root->val;
        }
        
        if (left_root_path_max > right_root_path_max) {
            int new_sum = root->val + left_root_path_max;
            if (new_sum > to_return && new_sum > 0) {
                to_return = new_sum;
            }
        } else {
            int new_sum = root->val + right_root_path_max;
            if (new_sum > to_return && new_sum > 0) {
                 to_return = new_sum;
            }
        }
        return to_return;
    }   
    int maxPathSum(TreeNode* root) {
        int max = 0;
        bool start = false;
        maxRootPathSumHelper(root, max, start);
        return max;
    }
};
// @lc code=end