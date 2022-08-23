/*
 * @lc app=leetcode id=1646 lang=cpp
 *
 * [1646] Get Maximum in Generated Array
 *
 * https://leetcode.com/problems/get-maximum-in-generated-array/description/
 *
 * algorithms
 * Easy (50.35%)
 * Likes:    471
 * Dislikes: 643
 * Total Accepted:    69.9K
 * Total Submissions: 138.8K
 * Testcase Example:  '7'
 *
 * You are given an integer n. A 0-indexed integer array nums of length n + 1
 * is generated in the following way:
 * 
 * 
 * nums[0] = 0
 * nums[1] = 1
 * nums[2 * i] = nums[i] when 2 <= 2 * i <= n
 * nums[2 * i + 1] = nums[i] + nums[i + 1] when 2 <= 2 * i + 1 <= n
 * 
 * 
 * Return the maximum integer in the array nums​​​.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 7
 * Output: 3
 * Explanation: According to the given rules:
 * ⁠ nums[0] = 0
 * ⁠ nums[1] = 1
 * ⁠ nums[(1 * 2) = 2] = nums[1] = 1
 * ⁠ nums[(1 * 2) + 1 = 3] = nums[1] + nums[2] = 1 + 1 = 2
 * ⁠ nums[(2 * 2) = 4] = nums[2] = 1
 * ⁠ nums[(2 * 2) + 1 = 5] = nums[2] + nums[3] = 1 + 2 = 3
 * ⁠ nums[(3 * 2) = 6] = nums[3] = 2
 * ⁠ nums[(3 * 2) + 1 = 7] = nums[3] + nums[4] = 2 + 1 = 3
 * Hence, nums = [0,1,1,2,1,3,2,3], and the maximum is max(0,1,1,2,1,3,2,3) =
 * 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 2
 * Output: 1
 * Explanation: According to the given rules, nums = [0,1,1]. The maximum is
 * max(0,1,1) = 1.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 3
 * Output: 2
 * Explanation: According to the given rules, nums = [0,1,1,2]. The maximum is
 * max(0,1,1,2) = 2.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= n <= 100
 * 
 * 
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> nums(n + 1,0);
        if (n == 0) return 0;
        if (n == 1) return 1;
        nums.at(1) = 1;
        int max = 1;
        for (int i = 2; i <= n; i++) {
            int idx = i / 2;
            if (i % 2 == 0) {
                nums.at(i) = nums.at(idx);
            } else {
                nums.at(i) = nums.at(idx) + nums.at(idx + 1);
            }
            if (nums.at(i) > max) {
                max = nums.at(i);
            }
            // cout << nums.at(i) << ' ';
        }
        return max;
    }
};
// @lc code=end

