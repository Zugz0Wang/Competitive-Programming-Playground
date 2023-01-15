/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (48.27%)
 * Likes:    9420
 * Dislikes: 450
 * Total Accepted:    1.2M
 * Total Submissions: 2.4M
 * Testcase Example:  '[3,4,5,1,2]'
 *
 * Suppose an array of length n sorted in ascending order is rotated between 1
 * and n times. For example, the array nums = [0,1,2,4,5,6,7] might
 * become:
 * 
 * 
 * [4,5,6,7,0,1,2] if it was rotated 4 times.
 * [0,1,2,4,5,6,7] if it was rotated 7 times.
 * 
 * 
 * Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results
 * in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
 * 
 * Given the sorted rotated array nums of unique elements, return the minimum
 * element of this array.
 * 
 * You must write an algorithm that runs in O(log n) time.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [3,4,5,1,2]
 * Output: 1
 * Explanation: The original array was [1,2,3,4,5] rotated 3 times.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2]
 * Output: 0
 * Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4
 * times.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [11,13,15,17]
 * Output: 11
 * Explanation: The original array was [11,13,15,17] and it was rotated 4
 * times. 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == nums.length
 * 1 <= n <= 5000
 * -5000 <= nums[i] <= 5000
 * All the integers of nums are unique.
 * nums is sorted and rotated between 1 and n times.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        const int kSize = nums.size();
        const int pivot = nums.at(0);
        if (pivot <= nums.at(kSize - 1)) {
            return pivot;
        }

        int head = 1;
        int tail = kSize;
        while (head < tail) {
            int mid_idx = (head + tail) / 2;
            int mid_val = nums.at(mid_idx);
            int prev_val = nums.at(mid_idx - 1);
            if (prev_val > mid_val) {
                return mid_val;
            } else if (mid_val > pivot) {
                head = mid_idx + 1;
            } else {
                tail = mid_idx;
            }
            //cout<< mid_idx << ' ';
        }
        return -1;
    }
};
// @lc code=end

