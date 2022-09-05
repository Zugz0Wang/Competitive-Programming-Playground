/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/n-ary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (69.24%)
 * Likes:    2094
 * Dislikes: 94
 * Total Accepted:    195.6K
 * Total Submissions: 282.1K
 * Testcase Example:  '[1,null,3,2,4,null,5,6]'
 *
 * Given an n-ary tree, return the level order traversal of its nodes' values.
 * 
 * Nary-Tree input serialization is represented in their level order traversal,
 * each group of children is separated by the null value (See examples).
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: root = [1,null,3,2,4,null,5,6]
 * Output: [[1],[3,2,4],[5,6]]
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: root =
 * [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
 * Output: [[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The height of the n-ary tree is less than or equal to 1000
 * The total number of nodes is between [0, 10^4]
 * 
 * 
 */
#include <vector>
#include <queue>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// @lc code=start

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> to_return;
        if (root == nullptr) {
            return to_return;
        }
        queue<Node*> wait;
        wait.push(root);
        int level = 0;
        while(!wait.empty()) {
            int size = wait.size();
            int i = 0;
            to_return.push_back({});
            while (i < size) {
                Node* curr = wait.front();
                wait.pop();
                to_return.at(level).push_back(curr->val);
                vector<Node*>& next = curr->children;
                for (Node* i : next) {
                    wait.push(i);
                }
                i++;
            }
            level++;
        }
        return to_return;
    }
};
// @lc code=end

