/*
 * @lc app=leetcode id=863 lang=cpp
 *
 * [863] All Nodes Distance K in Binary Tree
 *
 * https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/
 *
 * algorithms
 * Medium (61.77%)
 * Likes:    8873
 * Dislikes: 175
 * Total Accepted:    319.2K
 * Total Submissions: 509.5K
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n2'
 *
 * Given the root of a binary tree, the value of a target node target, and an
 * integer k, return an array of the values of all nodes that have a distance k
 * from the target node.
 * 
 * You can return the answer in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
 * Output: [7,4,1]
 * Explanation: The nodes that are a distance 2 from the target node (with
 * value 5) have values 7, 4, and 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1], target = 1, k = 3
 * Output: []
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 500].
 * 0 <= Node.val <= 500
 * All the values Node.val are unique.
 * target is the value of one of the nodes in the tree.
 * 0 <= k <= 1000
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef pair<TreeNode*, TreeNode*> Info;
class Solution { // Independently solved
public:
    stack<pair<TreeNode*, TreeNode*>> s;
    TreeNode* t;
    vector<int> ans;

    bool find(TreeNode* root) {
        if (root == t) {
            s.push(Info(root, nullptr));
            return true;
        }

        if (root -> left) {
            s.push(Info(root, root->left));
            if (find(root->left)) {
                return true;
            }
            s.pop();
        }

        if (root->right) {
            s.push(Info(root, root->right));
            if (find(root->right)) {
                return true;
            }
            s.pop();
        }
        return false;
    }

    void bfs(TreeNode* root, TreeNode* avoid, int dis) {
        if (root == nullptr) {
            return;
        }
        if (dis == 0) {
            ans.push_back(root->val);
            return;
        }
        int curr_dis(1);
        queue<TreeNode*> q;
        
        if (root->left && root->left!=avoid)
            q.push(root->left);
        if (root->right && root->right!=avoid)
            q.push(root->right);
        while (curr_dis < dis) {
            const size_t size(q.size());
            for (size_t i(0); i < size; ++i) {
                TreeNode* curr(q.front());
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
                q.pop();
            }
            
            curr_dis += 1;
        }
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return;
    }

    vector<int> distanceK(TreeNode* root_, TreeNode* target, int k) {
        t = target;
        find(root_);
        while (!s.empty() && k >= 0) {
            Info curr(s.top());
            s.pop();
            bfs(curr.first, curr.second, k);
            k -= 1;
            // cout << curr.first -> val << "  <- ";
        }

        
        return ans;
    }
};
// @lc code=end

