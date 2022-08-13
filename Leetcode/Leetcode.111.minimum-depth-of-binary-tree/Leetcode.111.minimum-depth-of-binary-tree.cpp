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
    int minDepthEdge(TreeNode* root) {
        if (root == nullptr) {
            return -1;
        }
        
        int left_h = minDepthEdge(root->left);
        int right_h = minDepthEdge(root->right);
        int to_return = 0;
        if (left_h != -1 && right_h != -1) { // Ignore -1 edge
            if (left_h <= right_h) {
                to_return = left_h + 1;
            } else {
                to_return = right_h + 1;
            }
        } else if (left_h != -1) {
            to_return = left_h + 1;
        } else if (right_h != -1) {
            to_return = right_h + 1;
        } else {
            to_return = 0;
        }

        return to_return;
    }
    
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        return minDepthEdge(root) + 1;
    }
};