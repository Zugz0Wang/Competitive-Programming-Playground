/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 */
#include <vector>
#include <string>
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
    void binaryTreeHelper(TreeNode* root, string path, vector<string>& to_return) {
        if (root == nullptr) {
            return;
        }
        path += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) { // If leaf node
            to_return.push_back(path);
        } else { // If internal node
            path += "->";
            if (root->left) binaryTreeHelper(root->left, path, to_return);
            if (root->right) binaryTreeHelper(root->right, path, to_return);
        }
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> to_return;
        string path;
        binaryTreeHelper(root, path, to_return);
        return to_return;
    }
};
// @lc code=end

