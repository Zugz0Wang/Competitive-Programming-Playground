/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (65.31%)
 * Likes:    6790
 * Dislikes: 196
 * Total Accepted:    716.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * chosen from the range [1, n].
 * 
 * You may return the answer in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 4, k = 2
 * Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
 * Explanation: There are 4 choose 2 = 6 total combinations.
 * Note that combinations are unordered, i.e., [1,2] and [2,1] are considered
 * to be the same combination.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1, k = 1
 * Output: [[1]]
 * Explanation: There is 1 choose 1 = 1 total combination.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 20
 * 1 <= k <= n
 * 
 * 
 */

// @lc code=start
class Solution { // Independently solved
public:
    vector<int> path;
    vector<vector<int>> ans;
    size_t n;
    void helper(size_t from, size_t k) {
        
        for (size_t i(from); i <= n - k; ++i) {
            path.push_back(i);
            if (k > 0) {
                helper(i + 1, k - 1);
            } else {
                ans.push_back(path);
            }
            path.pop_back();
        }

    }
    vector<vector<int>> combine(int n_, int k) {
        n = n_;
        helper(1, k - 1);
        return ans;
    }
};
// @lc code=end

