/*
 * @lc app=leetcode id=918 lang=cpp
 *
 * [918] Maximum Sum Circular Subarray
 *
 * https://leetcode.com/problems/maximum-sum-circular-subarray/description/
 *
 * algorithms
 * Medium (37.76%)
 * Likes:    4249
 * Dislikes: 194
 * Total Accepted:    153K
 * Total Submissions: 392.4K
 * Testcase Example:  '[1,-2,3,-2]'
 *
 * Given a circular integer array nums of length n, return the maximum possible
 * sum of a non-empty subarray of nums.
 * 
 * A circular array means the end of the array connects to the beginning of the
 * array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the
 * previous element of nums[i] is nums[(i - 1 + n) % n].
 * 
 * A subarray may only include each element of the fixed buffer nums at most
 * once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there
 * does not exist i <= k1, k2 <= j with k1 % n == k2 % n.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,-2,3,-2]
 * Output: 3
 * Explanation: Subarray [3] has maximum sum 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,-3,5]
 * Output: 10
 * Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [-3,-2,-3]
 * Output: -2
 * Explanation: Subarray [-2] has maximum sum -2.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == nums.length
 * 1 <= n <= 3 * 10^4
 * -3 * 10^4 <= nums[i] <= 3 * 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int max(int a, int b) {
        if (a > b) {
            return a;
        } else {
            return b;
        }
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        const int kSize = nums.size();
        int max_val = nums.at(0);
        int total = 0;
        int sum = 0;

        for (int num : nums) {
            sum += num;
            total += num;
            max_val = max(max_val, sum);
            if (sum < 0) {
                sum = 0;
            }
            
        }
        if (kSize > 2) {
            int max_head = nums.at(0);
            int tail_sum = total - max_head - nums.at(1);
            int head_sum = nums.at(0);
            if (head_sum > max_head) {
                max_head = head_sum;
            }
            max_val = max(max_head + tail_sum, max_val);
            for (int i = 2; i < kSize; i++) {
                head_sum += nums.at(i - 1);
                tail_sum -= nums.at(i);
                if (head_sum > max_head) {
                    max_head = head_sum;
                }
                max_val = max(max_head + tail_sum, max_val);
            }
        }
        
        return max_val;
    }
    //[5,-3,5]
};
// @lc code=end

