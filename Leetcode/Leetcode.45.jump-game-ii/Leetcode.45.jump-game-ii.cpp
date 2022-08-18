/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 *
 * https://leetcode.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Medium (38.08%)
 * Likes:    9168
 * Dislikes: 326
 * Total Accepted:    678.2K
 * Total Submissions: 1.8M
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers nums, you are initially positioned
 * at the first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Your goal is to reach the last index in the minimum number of jumps.
 * 
 * You can assume that you can always reach the last index.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,3,1,1,4]
 * Output: 2
 * Explanation: The minimum number of jumps to reach the last index is 2. Jump
 * 1 step from index 0 to 1, then 3 steps to the last index.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [2,3,0,1,4]
 * Output: 2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^4
 * 0 <= nums[i] <= 1000
 * 
 * 
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        const int kSize = nums.size();
        vector<bool> reachable(kSize, false);
        vector<int> steps(kSize, false);
        reachable.at(kSize - 1) = true;
        int idx = kSize - 2;
        while (idx >= 0) {
            int max_step = nums.at(idx);
            int step = 1;
            bool reach = false;
            int min_step = 0;
            while (idx + step < kSize && step <= max_step) { // If this can reach an idx that can reach the final idx
                if (reachable.at(idx + step) == true) {
                    int curr_step = steps.at(idx + step);
                    if (reach == false) {
                        reach = true;
                        min_step =curr_step;
                    } else if (curr_step < min_step) {
                        min_step = curr_step;
                    }
                }
                step++;
            }
            reachable.at(idx) = reach;
            steps.at(idx) = min_step + 1;
            idx--;
        }
        // for (int i : steps) {
        //     cout << i << ' ';
        // }
        return steps.at(0);
        
    }
};
// @lc code=end

