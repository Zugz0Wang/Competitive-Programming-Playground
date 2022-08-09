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
    bool isSameHelper(TreeNode* p, TreeNode* q) {
        if (p == nullptr || q == nullptr) { // Checking whether they are same as well as making sure not dereferencing nullptr! Smooth!
            if (p == q) {
                return true;
            } else {
                return false;
            }
        }
        return (p->val == q->val) && isSameHelper(p->left,q->left) && isSameHelper(p->right, q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isSameHelper(p, q);
    }
};