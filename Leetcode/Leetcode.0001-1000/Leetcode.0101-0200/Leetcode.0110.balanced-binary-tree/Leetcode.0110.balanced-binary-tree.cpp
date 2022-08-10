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
    
    int depth(TreeNode* root) { // Normal edge counting depth
        if (root == nullptr) {
            return -1;
        }
        int left_height = 0;
        left_height = 1 + depth(root->left);
        int right_height = 0;
        right_height = 1 + depth(root->right);
        int sub_height = 0;
        if (left_height > right_height) {
            sub_height = left_height;
        } else {
            sub_height = right_height;
        }
        // cout << root->val << ' ' << sub_height << '\n';
        return sub_height;
    }
    
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        int diff = depth(root->left) - depth(root->right);
        if (diff != 1 && diff != -1 && diff != 0) {
            return false;
        }
        
        return isBalanced(root->left) && isBalanced(root->right);
    }
};