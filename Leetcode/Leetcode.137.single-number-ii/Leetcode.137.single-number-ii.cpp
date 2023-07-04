/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 *
 * https://leetcode.com/problems/single-number-ii/description/
 *
 * algorithms
 * Medium (57.26%)
 * Likes:    6131
 * Dislikes: 570
 * Total Accepted:    440.5K
 * Total Submissions: 739.2K
 * Testcase Example:  '[2,2,3,2]'
 *
 * Given an integer array nums where every element appears three times except
 * for one, which appears exactly once. Find the single element and return it.
 * 
 * You must implement a solution with a linear runtime complexity and use only
 * constant extra space.
 * 
 * 
 * Example 1:
 * Input: nums = [2,2,3,2]
 * Output: 3
 * Example 2:
 * Input: nums = [0,1,0,1,0,1,99]
 * Output: 99
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 3 * 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * Each element in nums appears exactly three times except for one element
 * which appears once.
 * 
 * 
 */

// @lc code=start
class Solution { // Independently solved
public:
    int singleNumber(vector<int>& nums) {
        int a(0);
        int b(0);
        for (int num : nums) {
            int count0(~a);
            int count1(a);
            int count2(a & b);
            a = a | (num & count0);
            b = b | (num & count1);
            a = a & (~(num & count2));
            b = b & (~(num & count2));
        }
        return a;
    }
};
// @lc code=end

