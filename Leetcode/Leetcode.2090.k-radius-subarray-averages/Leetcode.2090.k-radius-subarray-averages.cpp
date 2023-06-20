/*
 * @lc app=leetcode id=2090 lang=cpp
 *
 * [2090] K Radius Subarray Averages
 *
 * https://leetcode.com/problems/k-radius-subarray-averages/description/
 *
 * algorithms
 * Medium (41.86%)
 * Likes:    544
 * Dislikes: 29
 * Total Accepted:    25.8K
 * Total Submissions: 60.6K
 * Testcase Example:  '[7,4,3,9,1,8,5,2,6]\n3'
 *
 * You are given a 0-indexed array nums of n integers, and an integer k.
 * 
 * The k-radius average for a subarray of nums centered at some index i with
 * the radius k is the average of all elements in nums between the indices i -
 * k and i + k (inclusive). If there are less than k elements before or after
 * the index i, then the k-radius average is -1.
 * 
 * Build and return an array avgs of length n where avgs[i] is the k-radius
 * average for the subarray centered at index i.
 * 
 * The average of x elements is the sum of the x elements divided by x, using
 * integer division. The integer division truncates toward zero, which means
 * losing its fractional part.
 * 
 * 
 * For example, the average of four elements 2, 3, 1, and 5 is (2 + 3 + 1 + 5)
 * / 4 = 11 / 4 = 2.75, which truncates to 2.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [7,4,3,9,1,8,5,2,6], k = 3
 * Output: [-1,-1,-1,5,4,4,-1,-1,-1]
 * Explanation:
 * - avg[0], avg[1], and avg[2] are -1 because there are less than k elements
 * before each index.
 * - The sum of the subarray centered at index 3 with radius 3 is: 7 + 4 + 3 +
 * 9 + 1 + 8 + 5 = 37.
 * ⁠ Using integer division, avg[3] = 37 / 7 = 5.
 * - For the subarray centered at index 4, avg[4] = (4 + 3 + 9 + 1 + 8 + 5 + 2)
 * / 7 = 4.
 * - For the subarray centered at index 5, avg[5] = (3 + 9 + 1 + 8 + 5 + 2 + 6)
 * / 7 = 4.
 * - avg[6], avg[7], and avg[8] are -1 because there are less than k elements
 * after each index.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [100000], k = 0
 * Output: [100000]
 * Explanation:
 * - The sum of the subarray centered at index 0 with radius 0 is: 100000.
 * ⁠ avg[0] = 100000 / 1 = 100000.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [8], k = 100000
 * Output: [-1]
 * Explanation: 
 * - avg[0] is -1 because there are less than k elements before and after index
 * 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == nums.length
 * 1 <= n <= 10^5
 * 0 <= nums[i], k <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) { // Independently solved
        const size_t size(nums.size());
        vector<int> ans(size, -1);
        const size_t range(2 * k + 1);
        if (size < range) {
            return ans;
        }
        long sum(0);
        for (size_t i(0); i < range; ++i) {
            sum += nums.at(i);
        }
        size_t left_i(0);
        size_t right_i(range);
        for (size_t i(k); i < size - k; ++i) {
            ans.at(i) = sum / range;
            // cout << sum << ' ';
            if (i < size - k - 1) {
                sum -= nums.at(left_i);
                sum += nums.at(right_i);
                right_i += 1;
                left_i += 1;
            }
            
        }

        return ans;
    }
};
// @lc code=end

