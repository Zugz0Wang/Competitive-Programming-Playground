/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 *
 * https://leetcode.com/problems/increasing-triplet-subsequence/description/
 *
 * algorithms
 * Medium (41.65%)
 * Likes:    5373
 * Dislikes: 249
 * Total Accepted:    333.9K
 * Total Submissions: 788.3K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given an integer array nums, return true if there exists a triple of indices
 * (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such
 * indices exists, return false.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,4,5]
 * Output: true
 * Explanation: Any triplet where i < j < k is valid.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,4,3,2,1]
 * Output: false
 * Explanation: No triplet exists.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [2,1,5,0,4,6]
 * Output: true
 * Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4]
 * == 4 < nums[5] == 6.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 5 * 10^5
 * -2^31 <= nums[i] <= 2^31 - 1
 * 
 * 
 * 
 * Follow up: Could you implement a solution that runs in O(n) time complexity
 * and O(1) space complexity?
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        bool looking_second = false;
        bool looking_third = false;
        int first0 = 0;
        int first1 = 0;
       
        int second0 = 0;
        for (int i : nums) {
            if (looking_third && i > second0) {
                return true;
            }
            if ((!looking_third && looking_second && i > first1) || (looking_second && i > first1 && i < second0)) {
                first0 = first1;
                second0 = i;
                looking_third = true;
            }

            if (!looking_second || (i < first1)) {
                first1 = i;
                looking_second = true;
            }
        }
        return false;
    }
};
// @lc code=end

