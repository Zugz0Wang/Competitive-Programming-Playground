/*
 * @lc app=leetcode id=1799 lang=cpp
 *
 * [1799] Maximize Score After N Operations
 *
 * https://leetcode.com/problems/maximize-score-after-n-operations/description/
 *
 * algorithms
 * Hard (45.88%)
 * Likes:    543
 * Dislikes: 50
 * Total Accepted:    16.8K
 * Total Submissions: 35.8K
 * Testcase Example:  '[1,2]'
 *
 * You are given nums, an array of positive integers of size 2 * n. You must
 * perform n operations on this array.
 * 
 * In the i^th operation (1-indexed), you will:
 * 
 * 
 * Choose two elements, x and y.
 * Receive a score of i * gcd(x, y).
 * Remove x and y from nums.
 * 
 * 
 * Return the maximum score you can receive after performing n operations.
 * 
 * The function gcd(x, y) is the greatest common divisor of x and y.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2]
 * Output: 1
 * Explanation: The optimal choice of operations is:
 * (1 * gcd(1, 2)) = 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [3,4,6,8]
 * Output: 11
 * Explanation: The optimal choice of operations is:
 * (1 * gcd(3, 6)) + (2 * gcd(4, 8)) = 3 + 8 = 11
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,2,3,4,5,6]
 * Output: 14
 * Explanation: The optimal choice of operations is:
 * (1 * gcd(1, 5)) + (2 * gcd(2, 4)) + (3 * gcd(3, 6)) = 1 + 4 + 9 = 14
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 7
 * nums.length == 2 * n
 * 1 <= nums[i] <= 10^6
 * 
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution { 
// Learned from solution
// Key: use bit_mask to represent current search state.
public:

    vector<int> nums;
    size_t n;

    int gcd_memo[14][14] = {};

    int** dp;

    int helper(size_t i, size_t bit_mask) {
        if (i >= n) {
            return 0;
        }
        
        int& curr(dp[i][bit_mask]);

        if (curr == 0) {
            for (size_t j(0); j < 2 * n; ++j) {
                if ((bit_mask >> j) % 2 == 1) { // If the number has being used
                    continue;
                }

                for (size_t k(j + 1); k < 2 * n; ++k) {
                    if ((bit_mask >> k) % 2 == 1) { // If the number has being used
                        continue;
                    }
                    size_t new_mask((1 << j) + (1 << k));
                    int& curr_gcd(gcd_memo[j][k]);
                    if (curr_gcd == 0) { // Memorizing gcd results
                        curr_gcd = __gcd(nums.at(j), nums.at(k));
                    }
                    curr = max(curr, curr_gcd * (int)(i + 1) + helper(i + 1, bit_mask + new_mask)); // If we have better ans
                }
            }
        }

        return curr;
    }

    int maxScore(vector<int>& nums_) {
        nums = nums_;
        n = nums_.size() / 2;
        dp = new int*[n];
        size_t all(pow(2, 2 * n));

        for (size_t i(0); i < n; ++i) { // Initialize dp array
            dp[i] = new int[all];
            for (size_t j(0); j < all; ++j) {
                dp[i][j] = 0;
            }
        }

        int ans(helper(0, 0));

        for (size_t i(0); i < n; ++i) { // Release memo
            delete[] dp[i];
        }
        delete[] dp;

        return ans;
    }
};
// @lc code=end

