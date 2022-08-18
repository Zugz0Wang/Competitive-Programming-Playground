/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 *
 * https://leetcode.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (38.22%)
 * Likes:    12509
 * Dislikes: 666
 * Total Accepted:    1.1M
 * Total Submissions: 2.9M
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * You are given an integer array nums. You are initially positioned at the
 * array's first index, and each element in the array represents your maximum
 * jump length at that position.
 * 
 * Return true if you can reach the last index, or false otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last
 * index.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its maximum
 * jump length is 0, which makes it impossible to reach the last index.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^4
 * 0 <= nums[i] <= 10^5
 * 
 * 
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int kSize = nums.size();
        vector<bool> reachable(kSize, false);
        reachable.at(kSize - 1) = true;
        int idx = kSize - 2;
        while (idx >= 0) {
            int max_step = nums.at(idx);
            int step = 1;
            bool reach = false;
            while (idx + step < kSize && step <= max_step) { // If this can reach an idx that can reach the final idx
                if (reachable.at(idx + step) == true) {
                    reach = true;
                    break;
                }
                step++;
            }
            reachable.at(idx) = reach;
            idx--;
        }
        
        return reachable.at(0);
    }
};
// @lc code=end

