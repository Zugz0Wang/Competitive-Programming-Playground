/*
 * @lc app=leetcode id=673 lang=cpp
 *
 * [673] Number of Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (41.69%)
 * Likes:    5196
 * Dislikes: 210
 * Total Accepted:    156K
 * Total Submissions: 356.5K
 * Testcase Example:  '[1,3,5,4,7]'
 *
 * Given an integer array nums, return the number of longest increasing
 * subsequences.
 * 
 * Notice that the sequence has to be strictly increasing.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,3,5,4,7]
 * Output: 2
 * Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and
 * [1, 3, 5, 7].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [2,2,2,2,2]
 * Output: 5
 * Explanation: The length of the longest increasing subsequence is 1, and
 * there are 5 increasing subsequences of length 1, so output 5.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 2000
 * -10^6 <= nums[i] <= 10^6
 * 
 * 
 */

// @lc code=start
class Solution { // Independently solved;
public:
    int* dp;
    int findNumberOfLIS(vector<int>& nums) {
        const size_t size(nums.size());
        vector<int> dp_v(size * 2, 1);
        dp = dp_v.data();
        

        for (size_t i(1); i < size; ++i) {
            int& curr_len(dp[i * 2]);
            int& curr_num(dp[i * 2 + 1]);
            int curr(nums.at(i));
            for (size_t j(0); j < i; ++j) {
                int prev(nums.at(j));
                int prev_len(dp[j * 2]);
                int prev_num(dp[j * 2 + 1]);
                if (prev < curr) {
                    if (prev_len + 1 > curr_len) {
                        curr_len = prev_len + 1;
                        curr_num = prev_num;
                    } else if (prev_len + 1 == curr_len) {
                        curr_num += prev_num;
                    }
                }
            }
        }

        int max_len(0);
        int max_num(0);
        for (size_t i(0); i < size; ++i) {
            int curr_len(dp[i * 2]);
            int curr_num(dp[i * 2 + 1]);
            // cout << curr_len << ' ' << curr_num << ' ';
            if (curr_len > max_len) {
                max_len = curr_len;
                max_num = curr_num;
            } else if (curr_len == max_len) {
                max_num += curr_num;
            }
        }

        return max_num;
    }
};
// @lc code=end

