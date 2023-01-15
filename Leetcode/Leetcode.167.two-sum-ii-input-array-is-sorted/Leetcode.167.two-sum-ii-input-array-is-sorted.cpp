/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 *
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
 *
 * algorithms
 * Medium (59.82%)
 * Likes:    8528
 * Dislikes: 1141
 * Total Accepted:    1.3M
 * Total Submissions: 2.2M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given a 1-indexed array of integers numbers that is already sorted in
 * non-decreasing order, find two numbers such that they add up to a specific
 * target number. Let these two numbers be numbers[index1] and numbers[index2]
 * where 1 <= index1 < index2 <= numbers.length.
 * 
 * Return the indices of the two numbers, index1 and index2, added by one as an
 * integer array [index1, index2] of length 2.
 * 
 * The tests are generated such that there is exactly one solution. You may not
 * use the same element twice.
 * 
 * Your solution must use only constant extra space.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: numbers = [2,7,11,15], target = 9
 * Output: [1,2]
 * Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We
 * return [1, 2].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: numbers = [2,3,4], target = 6
 * Output: [1,3]
 * Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We
 * return [1, 3].
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: numbers = [-1,0], target = -1
 * Output: [1,2]
 * Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We
 * return [1, 2].
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= numbers.length <= 3 * 10^4
 * -1000 <= numbers[i] <= 1000
 * numbers is sorted in non-decreasing order.
 * -1000 <= target <= 1000
 * The tests are generated such that there is exactly one solution.
 * 
 * 
 */

// @lc code=start
class Solution {
public:

    vector<int> twoSum(vector<int>& numbers, int target) {
        const int kSize = numbers.size();
        int i = 0;
        int idx = -1;
        for (; i < kSize; i++) {
            int search = target - numbers.at(i);
            int head = i + 1;
            int tail = kSize;
            
            while (head < tail) {
                int mid_idx = (head + tail) / 2;
                int mid_val = numbers.at(mid_idx);
                if (mid_val == search) {
                    idx = mid_idx;
                    break;
                } else if (mid_val < search) {
                    head = mid_idx + 1;
                } else {
                    tail = mid_idx;
                }
            }
            if (idx >= 0) {
                break;
            }
        }
        return {i + 1, idx + 1};
    }// [-1, 0]\n-1
    //[2,3,4]\n6
};
// @lc code=end

