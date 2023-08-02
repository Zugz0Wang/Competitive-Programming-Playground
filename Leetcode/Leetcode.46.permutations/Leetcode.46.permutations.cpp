/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (73.80%)
 * Likes:    16686
 * Dislikes: 268
 * Total Accepted:    1.7M
 * Total Submissions: 2.2M
 * Testcase Example:  '[1,2,3]'
 *
 * Given an array nums of distinct integers, return all the possible
 * permutations. You can return the answer in any order.
 * 
 * 
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * Example 2:
 * Input: nums = [0,1]
 * Output: [[0,1],[1,0]]
 * Example 3:
 * Input: nums = [1]
 * Output: [[1]]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * All the integers of nums are unique.
 * 
 * 
 */

// @lc code=start
class Solution { // Independently solved
public:
    vector<int> path;
    vector<vector<int>> ans;
    int* nums;
    size_t n;
    void helper(size_t s, size_t k) {
        
        for (size_t i(0); i < n; ++i) {
            if ((s >> i) & 1 == 1) {
                continue;
            }
            path.push_back(nums[i]);
            s = s | (1 << i);
            if (k > 0) {
                helper(s, k - 1);
            } else {
                ans.push_back(path);
            }
            s = s & (~(1 << i));
            path.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums_) {
        n = nums_.size();
        nums = nums_.data();
        helper(0, n - 1);
        return ans;
    }
};
// @lc code=end

