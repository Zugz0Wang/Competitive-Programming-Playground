/*
 * @lc app=leetcode id=659 lang=cpp
 *
 * [659] Split Array into Consecutive Subsequences
 *
 * https://leetcode.com/problems/split-array-into-consecutive-subsequences/description/
 *
 * algorithms
 * Medium (45.92%)
 * Likes:    3623
 * Dislikes: 711
 * Total Accepted:    106K
 * Total Submissions: 212K
 * Testcase Example:  '[1,2,3,3,4,5]'
 *
 * You are given an integer array nums that is sorted in non-decreasing order.
 * 
 * Determine if it is possible to split nums into one or more subsequences such
 * that both of the following conditions are true:
 * 
 * 
 * Each subsequence is a consecutive increasing sequence (i.e. each integer is
 * exactly one more than the previous integer).
 * All subsequences have a length of 3 or more.
 * 
 * 
 * Return true if you can split nums according to the above conditions, or
 * false otherwise.
 * 
 * A subsequence of an array is a new array that is formed from the original
 * array by deleting some (can be none) of the elements without disturbing the
 * relative positions of the remaining elements. (i.e., [1,3,5] is a
 * subsequence of [1,2,3,4,5] while [1,3,2] is not).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,3,4,5]
 * Output: true
 * Explanation: nums can be split into the following subsequences:
 * [1,2,3,3,4,5] --> 1, 2, 3
 * [1,2,3,3,4,5] --> 3, 4, 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,3,3,4,4,5,5]
 * Output: true
 * Explanation: nums can be split into the following subsequences:
 * [1,2,3,3,4,4,5,5] --> 1, 2, 3, 4, 5
 * [1,2,3,3,4,4,5,5] --> 3, 4, 5
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,2,3,4,4,5]
 * Output: false
 * Explanation: It is impossible to split nums into consecutive increasing
 * subsequences of length 3 or more.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^4
 * -1000 <= nums[i] <= 1000
 * nums is sorted in non-decreasing order.
 * 
 * 
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> counter;
        unordered_map<int, int> need;
        for (int i : nums) {
            if (counter.count(i) == 0) {
                counter.insert(pair<int, int>(i, 1));
            } else {
                counter.at(i)++;
            }
        }
        for (int i : nums) {
            if (counter.at(i) > 0) {
                if (need.count(i) > 0 && need.at(i) > 0) {
                    need.at(i)--;
                    if (need.count(i + 1) > 0) {
                        need.at(i + 1)++;
                    } else {
                        need.insert(pair<int, int>(i + 1, 1));
                    }
                } else if (counter.count (i + 1) > 0 && counter.at(i + 1) > 0 && counter.count (i + 2) > 0 && counter.at(i + 2) > 0) {
                    counter.at(i + 1)--;
                    counter.at(i + 2)--;
                    if (need.count(i + 3) > 0) {
                        need.at(i + 3)++;
                    } else {
                        need.insert(pair<int, int>(i + 3, 1));
                    }
                } else {
                    return false;
                }
                counter.at(i)--;
            }
        }
        return true;
    }
};
// @lc code=end

