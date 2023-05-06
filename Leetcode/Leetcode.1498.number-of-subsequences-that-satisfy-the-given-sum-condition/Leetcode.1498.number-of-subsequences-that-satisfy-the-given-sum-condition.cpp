/*
 * @lc app=leetcode id=1498 lang=cpp
 *
 * [1498] Number of Subsequences That Satisfy the Given Sum Condition
 *
 * https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/
 *
 * algorithms
 * Medium (38.67%)
 * Likes:    1959
 * Dislikes: 177
 * Total Accepted:    43.8K
 * Total Submissions: 115.3K
 * Testcase Example:  '[3,5,6,7]\n9'
 *
 * You are given an array of integers nums and an integer target.
 * 
 * Return the number of non-empty subsequences of nums such that the sum of the
 * minimum and maximum element on it is less or equal to target. Since the
 * answer may be too large, return it modulo 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [3,5,6,7], target = 9
 * Output: 4
 * Explanation: There are 4 subsequences that satisfy the condition.
 * [3] -> Min value + max value <= target (3 + 3 <= 9)
 * [3,5] -> (3 + 5 <= 9)
 * [3,5,6] -> (3 + 6 <= 9)
 * [3,6] -> (3 + 6 <= 9)
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [3,3,6,8], target = 10
 * Output: 6
 * Explanation: There are 6 subsequences that satisfy the condition. (nums can
 * have repeated numbers).
 * [3] , [3] , [3,3], [3,6] , [3,6] , [3,3,6]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [2,3,3,4,6,7], target = 12
 * Output: 61
 * Explanation: There are 63 non-empty subsequences, two of them do not satisfy
 * the condition ([6,7], [7]).
 * Number of valid subsequences (63 - 2 = 61).
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^6
 * 1 <= target <= 10^6
 * 
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution { // Independently solved
public:
    const int mod = 1e9 + 7;

    size_t binarySearch(vector<int>& nums, int target, size_t begin, size_t end) {
        while (begin < end) {
            size_t mid_idx((begin + end) / 2);
            int mid_val(nums.at(mid_idx));
            if (mid_val > target) {
                end = mid_idx;
            } else {
                begin = mid_idx + 1;
            }
        }
        return begin;
    }

    int power2(size_t k) {
        int ans(1);
        int multiplier(2);

        while (k > 0) {
            if (k % 2 == 1) {
                ans = ((long)ans * multiplier) % mod;
            }
            multiplier = ((long)multiplier * multiplier) % mod;
            k /= 2;
        }
        return ans;
    }

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        size_t begin(0);
        size_t end(nums.size());

        int count(0);

        while (begin < end) {
            int begin_val(nums.at(begin));

            end = binarySearch(nums, target - begin_val, begin, end);
            // cout << end << '\n';
            if (begin >= end) {
                break;
            }

            size_t i(0); // Some optimization
            do {
                size_t length(end - begin - i - 1);
                ++i;
                count = ((long) count + power2(length)) % mod;
            } while (begin + i < end && nums.at(begin + i) == begin_val);
            begin += i;
        }
        return count;
    }
};
// @lc code=end

