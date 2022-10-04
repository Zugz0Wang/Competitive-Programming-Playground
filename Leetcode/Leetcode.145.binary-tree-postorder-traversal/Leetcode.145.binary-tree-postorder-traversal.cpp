// @lc app=leetcode id=145 lang=cpp
#include <vector>
using namespace std;
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
    void traversalHelper(TreeNode* root, vector<int>& to_return) { // Helper function
        if (root == nullptr) {
            return;
        }
        traversalHelper(root->left, to_return);
        traversalHelper(root->right, to_return);
        to_return.push_back(root->val); // Postporder
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> to_return;
        traversalHelper(root, to_return);
        return to_return;
    }
};
// @lc code=end