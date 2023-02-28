/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
 *
 * https://leetcode.com/problems/find-duplicate-subtrees/description/
 *
 * algorithms
 * Medium (56.27%)
 * Likes:    4108
 * Dislikes: 346
 * Total Accepted:    185.7K
 * Total Submissions: 327K
 * Testcase Example:  '[1,2,3,4,null,2,4,null,null,4]'
 *
 * Given the root of a binary tree, return all duplicate subtrees.
 * 
 * For each kind of duplicate subtrees, you only need to return the root node
 * of any one of them.
 * 
 * Two trees are duplicate if they have the same structure with the same node
 * values.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,2,3,4,null,2,4,null,null,4]
 * Output: [[2,4],[4]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [2,1,1]
 * Output: [[1]]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [2,2,2,3,null,3,null]
 * Output: [[2,3],[3]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of the nodes in the tree will be in the range [1, 5000]
 * -200 <= Node.val <= 200
 * 
 * 
 */

// Definition for a binary tree node.
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start

class Solution { // zugz0wang
public:
    int count = 0;
    
    TreeNode* val[5000];
    int left[5000];
    int right[5000];
    int height[5000];

    int dict[5000];
    bool single[5000];

    pair<int, int> traverseHeight(TreeNode* root) {
        int idx = count;
        if (root == nullptr) {
            return pair<int, int>(idx, -1);
        }
        
        val[idx] = root;
        ++count;
        TreeNode* left_node = root->left;
        TreeNode* right_node = root->right;
        int left_height = -1;
        int right_height = -1;
        if (left_node != nullptr) {
            pair<int, int> info = traverseHeight(left_node);
            left[idx] = info.first;
            left_height = info.second;
        } else {
            left[idx] = -1;
        }
        if (right_node != nullptr) {
            pair<int, int> info = traverseHeight(right_node);
            right[idx] = info.first;
            right_height = info.second;
        } else {
            right[idx] = -1;
        }

        if (left_height < right_height) {
            left_height = right_height;
        }
        height[idx] = 1 + left_height;

        return pair<int, int>(idx, 1 + left_height);
           
    }

    void uni(int i, int j) {
        int set_i = find(i);
        int set_j = find(j);
        dict[set_j] = set_i;
        single[set_i] = false;
    }

    int find(int i) {
        if (i < 0) {
            return -1;
        }
        if (dict[i] == i) {
            return i;
        }
        int ans = find(dict[i]);
        dict[i] = ans;
        return ans;
    }

    void compare(int i, int j) {
        if (val[i]->val != val[j]->val) {
            return;
        }
        if (find(left[i]) == find(left[j]) && find(right[i]) == find(right[j])) {
            uni(i, j);
        } 
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        traverseHeight(root);
        for (int i = 0; i < count; ++i) {
            dict[i] = i;
            single[i] = true;
        }
        int max_height = height[0];
        for (int h = 0; h < max_height; ++h) {
            for (int i = 0; i < count; ++i) {
                if (height[i] != h) {
                    continue;
                }
                for (int j = i + 1; j < count; ++j) {
                    if (height[j] != h) {
                        continue;
                    }
                    compare(i, j);
                }
            }
        }
        vector<TreeNode*> ans;
        for (int i = 0; i < count; ++i) {
            if (dict[i] == i && single[i]==false) {
                ans.push_back(val[i]);   
            }
        }
        return ans;
    }
};
// @lc code=end

