/*
 * @lc app=leetcode id=2369 lang=cpp
 *
 * [2369] Check if There is a Valid Partition For The Array
 *
 * https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/description/
 *
 * algorithms
 * Medium (38.67%)
 * Likes:    579
 * Dislikes: 105
 * Total Accepted:    21.5K
 * Total Submissions: 52.3K
 * Testcase Example:  '[4,4,4,5,6]'
 *
 * You are given a 0-indexed integer array nums. You have to partition the
 * array into one or more contiguous subarrays.
 * 
 * We call a partition of the array valid if each of the obtained subarrays
 * satisfies one of the following conditions:
 * 
 * 
 * The subarray consists of exactly 2 equal elements. For example, the subarray
 * [2,2] is good.
 * The subarray consists of exactly 3 equal elements. For example, the subarray
 * [4,4,4] is good.
 * The subarray consists of exactly 3 consecutive increasing elements, that is,
 * the difference between adjacent elements is 1. For example, the subarray
 * [3,4,5] is good, but the subarray [1,3,5] is not.
 * 
 * 
 * Return true if the array has at least one valid partition. Otherwise, return
 * false.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,4,4,5,6]
 * Output: true
 * Explanation: The array can be partitioned into the subarrays [4,4] and
 * [4,5,6].
 * This partition is valid, so we return true.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,1,1,2]
 * Output: false
 * Explanation: There is no valid partition for this array.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^6
 * 
 * 
 */

// @lc code=start
class Solution { // Independently solved
public:
    bool validPartition(vector<int>& nums_v) {
        const size_t size(nums_v.size());
        int* nums(nums_v.data());
        vector<bool> dp_v(size + 1, false);
        dp_v.at(0) = true;
        for (size_t i(1); i < size; ++i) {
            if (nums[i - 1] == nums[i] && dp_v.at(i - 1)) {
                dp_v.at(i + 1) = true;
            }
            if (i > 1 && nums[i - 1] == nums[i] && nums[i - 1] == nums[i - 2] && dp_v.at(i - 2)) {
                dp_v.at(i + 1) = true;
            }
            if (i > 1 && nums[i - 1] + 1 == nums[i] && nums[i - 2] + 1 == nums[i - 1] && dp_v.at(i - 2)) {
                dp_v.at(i + 1) = true;
            }
            // cout << (int) dp_v.at(i + 1) << "!\n";
        }
        return dp_v.at(size);
    }
};
// @lc code=end

