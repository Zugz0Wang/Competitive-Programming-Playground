/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (46.48%)
 * Likes:    7066
 * Dislikes: 385
 * Total Accepted:    893.3K
 * Total Submissions: 1.9M
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an integer array nums of length n and an integer target, find three
 * integers in nums such that the sum is closest to target.
 * 
 * Return the sum of the three integers.
 * 
 * You may assume that each input would have exactly one solution.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [-1,2,1,-4], target = 1
 * Output: 2
 * Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0,0,0], target = 1
 * Output: 0
 * Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 =
 * 0).
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 3 <= nums.length <= 1000
 * -1000 <= nums[i] <= 1000
 * -10^4 <= target <= 10^4
 * 
 * 
 */
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        const int kSize = nums.size();
        int first_idx = 0;
        int second_idx = 1;
        int third_idx = 2;
        int close = nums.at(first_idx) + nums.at(second_idx) + nums.at(third_idx);
        while (first_idx < kSize - 2) {
            if (first_idx > 0 && nums.at(first_idx) == nums.at(first_idx - 1)) {
                first_idx += 1;
                continue;
            }
            second_idx = first_idx + 1;
            third_idx = kSize - 1;
            while (second_idx < third_idx) {
                int curr_val = nums.at(first_idx) + nums.at(second_idx) + nums.at(third_idx);
                if (abs(curr_val - target) < abs(close - target)) {
                    // cout << curr_val << ' ' << abs(curr_val - target) << ' ' << abs(close - target) << '\n';
                    close = curr_val;
                }
                if (curr_val < target) {
                    second_idx += 1;
                } else if (curr_val == target) {
                    return target;
                } else {
                    third_idx -= 1;
                }
            }
            first_idx += 1;
        }
        return close;
    }
};
// @lc code=end

