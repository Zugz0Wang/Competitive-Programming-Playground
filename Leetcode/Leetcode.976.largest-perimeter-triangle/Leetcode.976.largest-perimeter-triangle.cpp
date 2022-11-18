/*
 * @lc app=leetcode id=976 lang=cpp
 *
 * [976] Largest Perimeter Triangle
 *
 * https://leetcode.com/problems/largest-perimeter-triangle/description/
 *
 * algorithms
 * Easy (53.10%)
 * Likes:    2334
 * Dislikes: 313
 * Total Accepted:    167.4K
 * Total Submissions: 305.3K
 * Testcase Example:  '[2,1,2]'
 *
 * Given an integer array nums, return the largest perimeter of a triangle with
 * a non-zero area, formed from three of these lengths. If it is impossible to
 * form any triangle of a non-zero area, return 0.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,1,2]
 * Output: 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,1]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 3 <= nums.length <= 10^4
 * 1 <= nums[i] <= 10^6
 * 
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        const int kSize = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = kSize - 3; i >= 0; i--) {
            int j = i + 1;
            int k = i + 2;
            if (nums.at(i) + nums.at(j) > nums.at(k)) {
                return nums.at(i) + nums.at(j) + nums.at(k);
            }
        }
        return 0;
    }
};
// @lc code=end

