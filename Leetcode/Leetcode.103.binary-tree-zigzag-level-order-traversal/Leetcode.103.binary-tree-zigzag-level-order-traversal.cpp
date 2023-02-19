/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (54.55%)
 * Likes:    8121
 * Dislikes: 213
 * Total Accepted:    870.9K
 * Total Submissions: 1.6M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given the root of a binary tree, return the zigzag level order traversal of
 * its nodes' values. (i.e., from left to right, then right to left for the
 * next level and alternate between).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[3],[20,9],[15,7]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1]
 * Output: [[1]]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = []
 * Output: []
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 2000].
 * -100 <= Node.val <= 100
 * 
 * 
 */
#include <vector>
#include <queue>
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

class Solution {// Original solution
public:
    void reverseVect(vector<int>& vect) {
        int head = 0;
        int tail = vect.size() - 1;
        while (head < tail) {
            int temp = vect.at(head);
            int& tail_ = vect.at(tail);
            vect.at(head) = tail_;
            tail_ = temp;
            ++head;
            --tail;
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        queue<TreeNode*> wait;
        bool reverse = false;
        wait.push(root);
        vector<vector<int>> ans;
        int layer_idx = 0;
        while (!wait.empty()) {
            int layer_size = wait.size();
            int i = 0;
            ans.push_back({});
            vector<int>& layer = ans.at(layer_idx);

            while (i < layer_size) {
                TreeNode* curr = wait.front();
                wait.pop();
                layer.push_back(curr->val);
                if (curr->left) {
                    wait.push(curr->left);
                }
                if (curr->right) {
                    wait.push(curr->right);
                }
                ++i;
            }
            if (reverse) {
                reverseVect(layer);
            }
            reverse = !reverse;
            layer_idx++;
        } 
        return ans;
    }
};
// @lc code=end

