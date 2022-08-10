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
    TreeNode* partialSortedArrayToBST(vector<int>& nums, int head, int tail) {
        if (head >= tail) { // Base case
            return nullptr;
        }
        int mid = (head + tail) / 2;
        TreeNode* left = partialSortedArrayToBST(nums, head, mid); // Left subtree
        TreeNode* right = partialSortedArrayToBST(nums, mid + 1, tail); // Right subtree
        return new TreeNode(nums.at(mid), left, right);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int head = 0;
        int tail = nums.size();
        return partialSortedArrayToBST(nums, head, tail);
    }
};