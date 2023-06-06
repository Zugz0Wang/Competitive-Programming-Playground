/*
 * @lc app=leetcode id=1502 lang=cpp
 *
 * [1502] Can Make Arithmetic Progression From Sequence
 *
 * https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/description/
 *
 * algorithms
 * Easy (68.81%)
 * Likes:    1157
 * Dislikes: 67
 * Total Accepted:    140.4K
 * Total Submissions: 205.8K
 * Testcase Example:  '[3,5,1]'
 *
 * A sequence of numbers is called an arithmetic progression if the difference
 * between any two consecutive elements is the same.
 * 
 * Given an array of numbers arr, return true if the array can be rearranged to
 * form an arithmetic progression. Otherwise, return false.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [3,5,1]
 * Output: true
 * Explanation: We can reorder the elements as [1,3,5] or [5,3,1] with
 * differences 2 and -2 respectively, between each consecutive elements.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [1,2,4]
 * Output: false
 * Explanation: There is no way to reorder the elements to obtain an arithmetic
 * progression.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= arr.length <= 1000
 * -10^6 <= arr[i] <= 10^6
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int prev(arr.at(1));
        const int diff(arr.at(0) - prev);
        const size_t size(arr.size());
        
        for (size_t i(2); i < size; ++i) {
            int curr(arr.at(i));
            int curr_diff(prev - curr);
            if (diff != curr_diff) {
                return false;
            }
            prev = curr;
        }
        return true;
    }
};
// @lc code=end

