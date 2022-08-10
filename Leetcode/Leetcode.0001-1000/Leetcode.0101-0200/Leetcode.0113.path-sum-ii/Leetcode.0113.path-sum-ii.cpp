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
class Solution {
public:
    bool isLeaf(TreeNode* root) {
        if (root==nullptr) return false;
        if (root->left || root->right) {
            return true;
        } else {
            return false;
        }
    }
    void pathSumHelper(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& all) { // DFS
        if (root == nullptr) {
            return;
        } else if (root->left == nullptr && root->right == nullptr) { // If leaf node. 
            if (targetSum == root->val) {
                path.push_back(root->val);
                all.push_back(path);
                path.pop_back();
                return;
            } else {
                return;
            }
        }
        int new_target = targetSum - root->val;
        path.push_back(root->val); // Search throught two subtrees
        pathSumHelper(root->left, new_target, path, all);
        pathSumHelper(root->right, new_target, path, all);
        path.pop_back(); // Switching to the brother subtree.
        return;
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> to_return;
        vector<int> path;
        pathSumHelper(root, targetSum, path, to_return);
        return to_return;
    }
};