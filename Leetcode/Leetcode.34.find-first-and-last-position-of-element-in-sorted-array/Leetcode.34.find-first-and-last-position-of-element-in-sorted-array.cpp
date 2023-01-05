/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (41.23%)
 * Likes:    15266
 * Dislikes: 364
 * Total Accepted:    1.4M
 * Total Submissions: 3.4M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in non-decreasing order, find the
 * starting and ending position of a given target value.
 * 
 * If target is not found in the array, return [-1, -1].
 * 
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * 
 * Example 1:
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * Example 2:
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * Example 3:
 * Input: nums = [], target = 0
 * Output: [-1,-1]
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * nums is a non-decreasing array.
 * -10^9 <= target <= 10^9
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        const int kSize = nums.size();
        int head = 0;
        int tail = kSize;
        int idx0 = -1;
        while (head < tail) {
            int mid_idx = (head + tail) / 2;
            int mid_val = nums.at(mid_idx);
            if (mid_val == target && (mid_idx == 0 || nums.at(mid_idx - 1) < target)) {
                idx0 = mid_idx;
                break;
            } else if (mid_val < target) {
                head = mid_idx + 1;
            } else {
                tail = mid_idx;
            }
        }
        head = 0;
        tail = kSize;
        int idx1 = -1;
        while (head < tail) {
            int mid_idx = (head + tail) / 2;
            int mid_val = nums.at(mid_idx);
            if (mid_val == target && (mid_idx >= kSize - 1 || nums.at(mid_idx + 1) > target)) {
                idx1 = mid_idx;
                break;
            } else if (mid_val <= target) {
                head = mid_idx + 1;
            } else {
                tail = mid_idx;
            }
        }
        return {idx0, idx1};
    }
};
// @lc code=end

