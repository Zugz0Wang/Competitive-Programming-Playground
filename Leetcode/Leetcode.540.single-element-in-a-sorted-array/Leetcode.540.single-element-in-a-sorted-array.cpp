/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
 *
 * https://leetcode.com/problems/single-element-in-a-sorted-array/description/
 *
 * algorithms
 * Medium (58.59%)
 * Likes:    7084
 * Dislikes: 117
 * Total Accepted:    364.9K
 * Total Submissions: 624.5K
 * Testcase Example:  '[1,1,2,3,3,4,4,8,8]'
 *
 * You are given a sorted array consisting of only integers where every element
 * appears exactly twice, except for one element which appears exactly once.
 * 
 * Return the single element that appears only once.
 * 
 * Your solution must run in O(log n) time and O(1) space.
 * 
 * 
 * Example 1:
 * Input: nums = [1,1,2,3,3,4,4,8,8]
 * Output: 2
 * Example 2:
 * Input: nums = [3,3,7,7,10,11,11]
 * Output: 10
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 0 <= nums[i] <= 10^5
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution { // Original Solution
public:
    int singleNonDuplicate(vector<int>& nums) {
        const int kSize = nums.size();
        int head = 0;
        int tail = kSize;
        while (head < tail) {
            int mid_idx = (head + tail) / 2;
            int mid_val = nums.at(mid_idx);
            if ((mid_idx == 0) || (mid_idx + 1 == kSize)) {
                return mid_val;
            }
            int prev_idx = mid_idx - 1;
            int prev_val = nums.at(prev_idx);
            int next_idx = mid_idx + 1;
            int next_val = nums.at(next_idx);
            if (mid_val == prev_val) {
                int prev_size = prev_idx;
                int next_size = kSize - next_idx;
                if (prev_size % 2 == 1) {
                    tail = prev_idx;
                } else {
                    head = next_idx;
                }
            } else if (mid_val == next_val) {
                int prev_size = mid_idx;
                int next_size = kSize - next_idx - 1;
                if (prev_size % 2 == 1) {
                    tail = mid_idx;
                } else {
                    head = next_idx + 1;
                }
            } else {
                return mid_val;
            }
        }
        return -1;
    }
};
// @lc code=end

