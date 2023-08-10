/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Medium (35.70%)
 * Likes:    6733
 * Dislikes: 875
 * Total Accepted:    545.1K
 * Total Submissions: 1.5M
 * Testcase Example:  '[2,5,6,0,0,1,2]\n0'
 *
 * There is an integer array nums sorted in non-decreasing order (not
 * necessarily with distinct values).
 * 
 * Before being passed to your function, nums is rotated at an unknown pivot
 * index k (0 <= k < nums.length) such that the resulting array is [nums[k],
 * nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
 * For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and
 * become [4,5,6,6,7,0,1,2,4,4].
 * 
 * Given the array nums after the rotation and an integer target, return true
 * if target is in nums, or false if it is not in nums.
 * 
 * You must decrease the overall operation steps as much as possible.
 * 
 * 
 * Example 1:
 * Input: nums = [2,5,6,0,0,1,2], target = 0
 * Output: true
 * Example 2:
 * Input: nums = [2,5,6,0,0,1,2], target = 3
 * Output: false
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 5000
 * -10^4 <= nums[i] <= 10^4
 * nums is guaranteed to be rotated at some pivot.
 * -10^4 <= target <= 10^4
 * 
 * 
 * 
 * Follow up: This problem is similar to Search in Rotated Sorted Array, but
 * nums may contain duplicates. Would this affect the runtime complexity? How
 * and why?
 * 
 */

// @lc code=start
lass Solution { // Independently solved
public:
    vector<int> nums;
    int pivot_val;
    int kSize;
    int target;
    bool helper(int head, int tail) {
        if (head >= tail) {
            return false;
        }

        int mid_idx = (head + tail) / 2;
        int mid_val = nums.at(mid_idx);
        if (mid_val == target) {
            return true;
        } 
        // cout << mid_idx <<' ';
        if (target > pivot_val) {
            if (mid_val > pivot_val) {
                if (mid_val > target) { 
                    // pivot_val < target < mid_val
                    return helper(head, mid_idx);
                } else {
                    // pivot_val < mid_val < target
                    head = mid_idx + 1;
                    return helper(mid_idx + 1, tail);
                }
            } else if (mid_val == pivot_val) {
                return helper(head, mid_idx) || helper(mid_idx + 1, tail);
            } else {
                //  mid_val < pivot_val < target
                return helper(head, mid_idx);
            }
        } else {
            if (mid_val > pivot_val) {
                // target < pivot_val < mid_val
                return helper(mid_idx + 1, tail);
            } else if (mid_val == pivot_val) {
                return helper(head, mid_idx) || helper(mid_idx + 1, tail);
            } else {
                if (mid_val > target) {
                    // target < mid_val < pivot_val
                    return helper(head, mid_idx);
                } else {
                    // mid_val < target < pivot_val
                    return helper(mid_idx + 1, tail);
                }
            }
        }
    }

    bool search(vector<int>& nums_, int target_) {
        target = target_;
        nums = nums_;
        kSize = nums.size();
        int head = 0;
        int tail = kSize;
        pivot_val = nums.at(0);
        if (pivot_val == target) {
            return true;
        }
        if (pivot_val >= nums.at(kSize - 1)) {
            return helper(head, tail);
        } else {
            while (head < tail) {
                int mid_idx = (head + tail) / 2;
                int mid_val = nums.at(mid_idx);
                if (mid_val == target) {
                    return true;
                } else if (mid_val > target) {
                    tail = mid_idx;
                } else {
                    head = mid_idx + 1;
                }
            }
            return false;
        }
    }
};
// @lc code=end

