/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (38.33%)
 * Likes:    19325
 * Dislikes: 1166
 * Total Accepted:    1.9M
 * Total Submissions: 4.8M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * There is an integer array nums sorted in ascending order (with distinct
 * values).
 * 
 * Prior to being passed to your function, nums is possibly rotated at an
 * unknown pivot index k (1 <= k < nums.length) such that the resulting array
 * is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]
 * (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3
 * and become [4,5,6,7,0,1,2].
 * 
 * Given the array nums after the possible rotation and an integer target,
 * return the index of target if it is in nums, or -1 if it is not in nums.
 * 
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * 
 * Example 1:
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * Example 2:
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * Example 3:
 * Input: nums = [1], target = 0
 * Output: -1
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 5000
 * -10^4 <= nums[i] <= 10^4
 * All values of nums are unique.
 * nums is an ascending array that is possibly rotated.
 * -10^4 <= target <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int kSize = nums.size();
        int head = 0;
        int tail = kSize;
        int pivot_val = nums.at(0);
        if (pivot_val == target) {
            return 0;
        }
        if (pivot_val > nums.at(kSize - 1)) {
            while (head < tail) {
                int mid_idx = (head + tail) / 2;
                int mid_val = nums.at(mid_idx);
                if (mid_val == target) {
                    return mid_idx;
                } 
                if (target > pivot_val) {
                    if (mid_val > pivot_val) {
                        if (mid_val > target) { 
                            // pivot_val < target < mid_val
                            tail = mid_idx;
                        } else {
                            // pivot_val < mid_val < target
                            head = mid_idx + 1;
                        }
                    } else {
                        //  mid_val < pivot_val < target
                        tail = mid_idx;
                    }
                } else {
                    if (mid_val > pivot_val) {
                        // target < pivot_val < mid_val
                        head = mid_idx + 1;
                    } else {
                        if (mid_val > target) {
                            // target < mid_val < pivot_val
                            tail = mid_idx;
                        } else {
                            // mid_val < target < pivot_val
                            head = mid_idx + 1;
                        }
                    }
                }
                

            }
            return -1;
        } else {
            while (head < tail) {
                int mid_idx = (head + tail) / 2;
                int mid_val = nums.at(mid_idx);
                if (mid_val == target) {
                    return mid_idx;
                } else if (mid_val > target) {
                    tail = mid_idx;
                } else {
                    head = mid_idx + 1;
                }
            }
            return -1;
        }
        
    }
    //[1,3]\n1
    //[4,5,6,7,0,1,2]\n5
};
// @lc code=end

