/*
 * @lc app=leetcode id=894 lang=cpp
 *
 * [894] All Possible Full Binary Trees
 *
 * https://leetcode.com/problems/all-possible-full-binary-trees/description/
 *
 * algorithms
 * Medium (79.83%)
 * Likes:    3000
 * Dislikes: 210
 * Total Accepted:    93.3K
 * Total Submissions: 116.9K
 * Testcase Example:  '7'
 *
 * Given an integer n, return a list of all possible full binary trees with n
 * nodes. Each node of each tree in the answer must have Node.val == 0.
 * 
 * Each element of the answer is the root node of one possible tree. You may
 * return the final list of trees in any order.
 * 
 * A full binary tree is a binary tree where each node has exactly 0 or 2
 * children.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 7
 * Output:
 * [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 3
 * Output: [[0,0,0]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 20
 * 
 * 
 */
#include <vector>
#include <iostream>
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
    vector<vector<TreeNode*>> dp;

    vector<TreeNode*> allPossibleFBTHelper(int n) {
        if (n % 2 == 0) {
            return {};
        }
        const int half = n / 2;
        // cout << half << '\n';
        if (dp.at(half).size() > 0) {
            return dp.at(half);
        }
        
        if (n == 1) {
            TreeNode* root= new TreeNode(0);
            dp.at(half).push_back(root);
            return dp.at(half);
        }
        
        for (int i = 1; i <= half; i += 2) {
            int left_n = i;
            int right_n = n - i - 1;
            // cout << left_n << ' ' << right_n << '\n';
            vector<TreeNode*> left_trees = allPossibleFBTHelper(left_n);
            vector<TreeNode*> right_trees = allPossibleFBTHelper(right_n);
            for (TreeNode* left_root : left_trees) {
                for (TreeNode* right_root : right_trees) {
                    TreeNode* root = new TreeNode(0, left_root, right_root);
                    dp.at(half).push_back(root);
                    if (left_n != right_n) {
                        root = new TreeNode(0, right_root, left_root);
                        dp.at(half).push_back(root);
                    }
                }
            }
            // cout << "Loop end\n";
        }
        
        return dp.at(half);
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0) {
            return {};
        }
        int half = n / 2 + 1;
        // cout << half << '\n';
        dp.assign(half, {});
        
        return allPossibleFBTHelper(n);
    }
};
// @lc code=end

