/*
 * @lc app=leetcode id=1732 lang=cpp
 *
 * [1732] Find the Highest Altitude
 *
 * https://leetcode.com/problems/find-the-highest-altitude/description/
 *
 * algorithms
 * Easy (78.71%)
 * Likes:    1521
 * Dislikes: 130
 * Total Accepted:    133.1K
 * Total Submissions: 166.8K
 * Testcase Example:  '[-5,1,5,0,-7]'
 *
 * There is a biker going on a road trip. The road trip consists of n + 1
 * points at different altitudes. The biker starts his trip on point 0 with
 * altitude equal 0.
 * 
 * You are given an integer array gain of length n where gain[i] is the net
 * gain in altitude between points i​​​​​​ and i + 1 for all (0 <= i < n).
 * Return the highest altitude of a point.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: gain = [-5,1,5,0,-7]
 * Output: 1
 * Explanation: The altitudes are [0,-5,-4,1,1,-6]. The highest is 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: gain = [-4,-3,-2,-1,4,3,2]
 * Output: 0
 * Explanation: The altitudes are [0,-4,-7,-9,-10,-6,-3,-1]. The highest is
 * 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == gain.length
 * 1 <= n <= 100
 * -100 <= gain[i] <= 100
 * 
 * 
 */

// @lc code=start
class Solution { // Independently solved
public:
    int largestAltitude(vector<int>& gains) {
        int val(0);
        int max_val(0);
        for (int gain : gains) {
            val += gain;
            if (val > max_val) {
                max_val = val;
            }
        }
        return max_val;
    }
};
// @lc code=end

