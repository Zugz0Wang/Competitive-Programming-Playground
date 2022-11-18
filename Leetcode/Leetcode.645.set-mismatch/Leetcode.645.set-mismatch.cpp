/*
 * @lc app=leetcode id=645 lang=cpp
 *
 * [645] Set Mismatch
 *
 * https://leetcode.com/problems/set-mismatch/description/
 *
 * algorithms
 * Easy (41.34%)
 * Likes:    3156
 * Dislikes: 731
 * Total Accepted:    237K
 * Total Submissions: 552.7K
 * Testcase Example:  '[1,2,2,4]'
 *
 * You have a set of integers s, which originally contains all the numbers from
 * 1 to n. Unfortunately, due to some error, one of the numbers in s got
 * duplicated to another number in the set, which results in repetition of one
 * number and loss of another number.
 * 
 * You are given an integer array nums representing the data status of this set
 * after the error.
 * 
 * Find the number that occurs twice and the number that is missing and return
 * them in the form of an array.
 * 
 * 
 * Example 1:
 * Input: nums = [1,2,2,4]
 * Output: [2,3]
 * Example 2:
 * Input: nums = [1,1]
 * Output: [1,2]
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= nums.length <= 10^4
 * 1 <= nums[i] <= 10^4
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool exist[10005] = {false};
    vector<int> findErrorNums(vector<int>& nums) {
        const int kSize = nums.size();
        vector<int> to_return;
        for (int num : nums) {
            if (exist[num]) {
                to_return.push_back(num);
            } else {
                exist[num] = true;
            }
        }
        for (int i = 1; i <= kSize; i++) {
            if (!exist[i]) {
                to_return.push_back(i);
            }
        }
        return to_return;
    }
};
// @lc code=end

