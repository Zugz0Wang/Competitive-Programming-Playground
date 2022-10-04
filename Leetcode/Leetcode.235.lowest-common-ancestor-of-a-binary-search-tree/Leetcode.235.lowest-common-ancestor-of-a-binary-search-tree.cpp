// @lc app=leetcode id=235 lang=cpp
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
    bool isAncestor(TreeNode* root, TreeNode* p) {
        if (root == nullptr) {
            return false;
        }
        
        if (root == p) {
            return true;
        }
        
        return isAncestor(root->left, p) || isAncestor(root->right, p);
    }
    bool isCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return isAncestor(root, p) && isAncestor(root, q);
    }
    
    void lowestCommonAncestorHelper(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& lowest) {
        if (isCommonAncestor(root, p, q)) { // This is kind of for the general binary tree, not BST.
            lowest = root;
        } else {
            return;
        }
        lowestCommonAncestorHelper(root->left, p, q, lowest);
        lowestCommonAncestorHelper(root->right, p, q, lowest);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* to_return = root;
        lowestCommonAncestorHelper(root, p, q, to_return);
        return to_return;
    }
};
// @lc code=end