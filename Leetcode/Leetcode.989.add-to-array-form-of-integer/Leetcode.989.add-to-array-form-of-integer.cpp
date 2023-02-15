/*
 * @lc app=leetcode id=989 lang=cpp
 *
 * [989] Add to Array-Form of Integer
 *
 * https://leetcode.com/problems/add-to-array-form-of-integer/description/
 *
 * algorithms
 * Easy (45.54%)
 * Likes:    1820
 * Dislikes: 171
 * Total Accepted:    145.5K
 * Total Submissions: 319.6K
 * Testcase Example:  '[1,2,0,0]\n34'
 *
 * The array-form of an integer num is an array representing its digits in left
 * to right order.
 * 
 * 
 * For example, for num = 1321, the array form is [1,3,2,1].
 * 
 * 
 * Given num, the array-form of an integer, and an integer k, return the
 * array-form of the integer num + k.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: num = [1,2,0,0], k = 34
 * Output: [1,2,3,4]
 * Explanation: 1200 + 34 = 1234
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: num = [2,7,4], k = 181
 * Output: [4,5,5]
 * Explanation: 274 + 181 = 455
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: num = [2,1,5], k = 806
 * Output: [1,0,2,1]
 * Explanation: 215 + 806 = 1021
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= num.length <= 10^4
 * 0 <= num[i] <= 9
 * num does not contain any leading zeros except for the zero itself.
 * 1 <= k <= 10^4
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> addToArrayForm(vector<int> num, int k) {
        int carry = 0;
        const int kSize = num.size();
        int idx = kSize - 1;
        while (k > 0) {
            int digit = k % 10;
            int& curr = num.at(idx);
            curr += curr + carry;
            if (curr > 10) {
                curr -= 10;
                carry = 1;
            }
            k /= 10;
        }
        return num;
    }
};
// @lc code=end

