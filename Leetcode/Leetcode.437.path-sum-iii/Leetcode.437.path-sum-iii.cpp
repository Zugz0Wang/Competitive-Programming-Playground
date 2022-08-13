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
    void pathSumHelper(TreeNode* root, int targetSum, vector<int>& path, int& count) { // DFS
        if (root == nullptr) {
            return;
        }
        int path_size = path.size();
        long long sum = 0;
        path.push_back(root->val); // Search through two subtrees
        for (int i = path_size; i >= 0; i--) { // Check if the sum of new subgroup matches targetSum
            sum += path.at(i);
            if (sum == targetSum) count++;
        }
        pathSumHelper(root->left, targetSum, path, count);
        pathSumHelper(root->right, targetSum, path, count);
        path.pop_back(); // Switching to the brother subtree.
        return;
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        vector<int> path;
        pathSumHelper(root, targetSum, path, count);
        return count;
    }
};