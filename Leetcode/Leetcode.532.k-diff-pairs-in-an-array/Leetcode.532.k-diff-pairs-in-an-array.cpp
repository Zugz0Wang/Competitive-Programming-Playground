/*
 * @lc app=leetcode id=532 lang=cpp
 *
 * [532] K-diff Pairs in an Array
 *
 * https://leetcode.com/problems/k-diff-pairs-in-an-array/description/
 *
 * algorithms
 * Medium (40.51%)
 * Likes:    2977
 * Dislikes: 2134
 * Total Accepted:    275.6K
 * Total Submissions: 676.9K
 * Testcase Example:  '[3,1,4,1,5]\n2'
 *
 * Given an array of integers nums and an integer k, return the number of
 * unique k-diff pairs in the array.
 * 
 * A k-diff pair is an integer pair (nums[i], nums[j]), where the following are
 * true:
 * 
 * 
 * 0 <= i, j < nums.length
 * i != j
 * nums[i] - nums[j] == k
 * 
 * 
 * Notice that |val| denotes the absolute value of val.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [3,1,4,1,5], k = 2
 * Output: 2
 * Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
 * Although we have two 1s in the input, we should only return the number of
 * unique pairs.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,3,4,5], k = 1
 * Output: 4
 * Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3,
 * 4) and (4, 5).
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,3,1,5,4], k = 0
 * Output: 1
 * Explanation: There is one 0-diff pair in the array, (1, 1).
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^4
 * -10^7 <= nums[i] <= 10^7
 * 0 <= k <= 10^7
 * 
 * 
 */
#include <vector>
#include <map>
using namespace std;
// @lc code=start
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int, int> s;
        for (int num : nums) {
            s[num]++;
        }
        int count = 0;
        for (pair<int, int> p : s) {
            if (s.count(p.first + k) > 0 && k != 0) {
                count += 1;
            } else if (k == 0 && p.second > 1) {
                count += 1;
            }
        }
        return count;
    }
};
// @lc code=end

