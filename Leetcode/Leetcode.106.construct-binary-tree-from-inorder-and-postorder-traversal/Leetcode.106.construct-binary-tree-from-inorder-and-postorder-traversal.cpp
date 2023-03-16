/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (56.66%)
 * Likes:    5933
 * Dislikes: 88
 * Total Accepted:    471.7K
 * Total Submissions: 808K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * Given two integer arrays inorder and postorder where inorder is the inorder
 * traversal of a binary tree and postorder is the postorder traversal of the
 * same tree, construct and return the binary tree.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
 * Output: [3,9,20,null,null,15,7]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: inorder = [-1], postorder = [-1]
 * Output: [-1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= inorder.length <= 3000
 * postorder.length == inorder.length
 * -3000 <= inorder[i], postorder[i] <= 3000
 * inorder and postorder consist of unique values.
 * Each value of postorder also appears in inorder.
 * inorder is guaranteed to be the inorder traversal of the tree.
 * postorder is guaranteed to be the postorder traversal of the tree.
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
#include <vector>
using namespace std;
// @lc code=start

class Solution {
public:
    int find(vector<int>& v, int head, int tail, int val) { // Original
        for (int i = head; i < tail; ++i) {
            if (v.at(i) == val) {
                return i;
            }
        }
        return -1;
    }
    TreeNode* helper(int in0, int in1, int post0, int post1, vector<int>& inorder, vector<int>& postorder) {
        if (in0 >= in1) {
            return nullptr;
        }
        int curr_val = postorder.at(post1 - 1);
        TreeNode* ans(new TreeNode(curr_val));
        int in_idx = find(inorder, in0, in1, curr_val);
        // cout << curr_val << ' ';
        if (in_idx < 0) {
            return nullptr;
        }
        int post_idx = post1 - (in1 - in_idx);
        
        ans->left = helper(in0, in_idx, post0, post_idx, inorder, postorder);
        ans->right = helper(in_idx + 1, in1, post_idx, post1 - 1, inorder, postorder);
        return ans;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        const int kSize0(inorder.size());
        const int kSize1(postorder.size());
        return helper(0, kSize0, 0, kSize1, inorder, postorder);
    }
};
// @lc code=end

