
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBSTHelper(TreeNode* root, bool left, int parent_val) { // Check if a tree's all nodes are less than or great than a value
        if (root == nullptr) {
            return true;
        }
        if (left) {
            if (root->val >= parent_val) {
                return false;
            }
        } else {
            if (root->val <= parent_val) {
                return false;
            }
        }
        return isValidBSTHelper(root->left, left, parent_val) && isValidBSTHelper(root->right, left, parent_val);
    }
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        int value = root->val;
        return isValidBSTHelper(root->left, true, value) && isValidBSTHelper(root->right, false, value) && isValidBST(root->left) && isValidBST(root->right);
    }
};