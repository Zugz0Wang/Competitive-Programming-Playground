/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (50.73%)
 * Likes:    5180
 * Dislikes: 338
 * Total Accepted:    323.6K
 * Total Submissions: 637.1K
 * Testcase Example:  '3'
 *
 * Given an integer n, return all the structurally unique BST's (binary search
 * trees), which has exactly n nodes of unique values from 1 to n. Return the
 * answer in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3
 * Output:
 * [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1
 * Output: [[1]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 8
 * 
 * 
 */
#include <vector>
using namespace std;
//Definition for a binary tree node.
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
    vector<TreeNode*> createTreeFromRange(int lower, int upper) { // [lower, upper)
        vector<TreeNode*> to_return;

        if (lower == upper) { // Base case, null tree.
            return to_return;
        }

        for (int i = lower; i < upper; i++) { // Pick a head value
            // vector<TreeNode*> left = createTreeFromRange(lower, i); lower, lower + 1,..., i - 2, i - 1, at the left side of the tree.
            // vector<TreeNode*> right = createTreeFromRange(i + 1, upper); i + 1, i + 2,..., upper - 2, upper - 1, at the left side of the tree.
            if (lower < i && i + 1 < upper) {
                vector<TreeNode*> left = createTreeFromRange(lower, i); 
                vector<TreeNode*> right = createTreeFromRange(i + 1, upper);
                for (TreeNode* j : left) { // Loop through every choice of left subtree.
                    for (TreeNode* k : right) { // Loop through every choice of right subtree.
                        TreeNode* root = new TreeNode;
                        root->val = i;
                        root->left = j;
                        root->right = k;
                        to_return.push_back(root);
                    }
                }
            } else if (lower < i) {
                vector<TreeNode*> left = createTreeFromRange(lower, i); 
                for (TreeNode* j : left) { // Loop through every choice of left subtree.
                    TreeNode* root = new TreeNode;
                    root->val = i;
                    root->left = j;
                    root->right = nullptr;
                    to_return.push_back(root);
                }
            } else if (i + 1 < upper) {
                vector<TreeNode*> right = createTreeFromRange(i + 1, upper);
                for (TreeNode* k : right) { // Loop through every choice of right subtree.
                    TreeNode* root = new TreeNode;
                    root->val = i;
                    root->left = nullptr;
                    root->right = k;
                    to_return.push_back(root);
                }
            } else {
                TreeNode* root = new TreeNode;
                root->val = i;
                to_return.push_back(root);
            }
            
        }
        return to_return;
        
    }
    vector<TreeNode*> generateTrees(int n) {
        return createTreeFromRange(1, n + 1);
    }
};
// @lc code=end

