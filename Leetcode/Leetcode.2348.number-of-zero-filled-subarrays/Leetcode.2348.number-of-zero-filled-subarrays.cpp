/*
 * @lc app=leetcode id=2348 lang=cpp
 *
 * [2348] Number of Zero-Filled Subarrays
 *
 * https://leetcode.com/problems/number-of-zero-filled-subarrays/description/
 *
 * algorithms
 * Medium (56.20%)
 * Likes:    545
 * Dislikes: 24
 * Total Accepted:    35.5K
 * Total Submissions: 58.3K
 * Testcase Example:  '[1,3,0,0,2,0,0,4]'
 *
 * Given an integer array nums, return the number of subarrays filled with 0.
 * 
 * A subarray is a contiguous non-empty sequence of elements within an
 * array.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,3,0,0,2,0,0,4]
 * Output: 6
 * Explanation: 
 * There are 4 occurrences of [0] as a subarray.
 * There are 2 occurrences of [0,0] as a subarray.
 * There is no occurrence of a subarray with a size more than 2 filled with 0.
 * Therefore, we return 6.
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0,0,0,2,0,0]
 * Output: 9
 * Explanation:
 * There are 5 occurrences of [0] as a subarray.
 * There are 3 occurrences of [0,0] as a subarray.
 * There is 1 occurrence of [0,0,0] as a subarray.
 * There is no occurrence of a subarray with a size more than 3 filled with 0.
 * Therefore, we return 9.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [2,10,2019]
 * Output: 0
 * Explanation: There is no subarray filled with 0. Therefore, we return 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) { // Original
        long long count(0);
        long long total(0);
        for (int num: nums) {
            if (num != 0) {
                if (count % 2 == 0) {
                    total += (count / 2) * (count + 1);
                } else {
                    total += ((count + 1) / 2) * count;
                }
                count = 0;
            } else {
                ++count;
            }
            
        }
        if (count % 2 == 0) {
            total += (count / 2) * (count + 1);
        } else {
            total += ((count + 1) / 2) * count;
        }
                
        return total;
    }
};
// @lc code=end

