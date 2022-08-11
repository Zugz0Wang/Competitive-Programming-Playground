#include <vector>
using namespace std;
//Definition for a binary tree node.
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
    void iterate(TreeNode* root, int& prev, int& count, int& max_count, bool& start, vector<int>& curr_res) {
        if (root == nullptr) { // See this process as a normal 1D array looping
            return;
        }
        iterate(root->left, prev, count, max_count, start, curr_res);
        int value = root->val;
        if (start == false) {
            start = true;
            prev = value;
            count = 1;
        } else {
            if (value == prev) {
                count++;
            } else {
                count = 1;
                prev = value;
            }
        }
        if (count == max_count) {
            curr_res.push_back(value);
        } else if (count > max_count) {
            max_count = count;
            curr_res.clear();
            curr_res.push_back(value);
        }
        iterate(root->right, prev, count, max_count, start, curr_res);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> to_return;
        bool start = false;
        int count = 0;
        int max_count = 0;
        int prev = 0;
        iterate(root, prev, count, max_count, start, to_return);
        return to_return;
    }
};