/*
 * @lc app=leetcode id=1539 lang=cpp
 *
 * [1539] Kth Missing Positive Number
 *
 * https://leetcode.com/problems/kth-missing-positive-number/description/
 *
 * algorithms
 * Easy (55.76%)
 * Likes:    3275
 * Dislikes: 235
 * Total Accepted:    200.5K
 * Total Submissions: 358.4K
 * Testcase Example:  '[2,3,4,7,11]\n5'
 *
 * Given an array arr of positive integers sorted in a strictly increasing
 * order, and an integer k.
 * 
 * Return the k^th positive integer that is missing from this array.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [2,3,4,7,11], k = 5
 * Output: 9
 * Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The
 * 5^th missing positive integer is 9.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [1,2,3,4], k = 2
 * Output: 6
 * Explanation: The missing positive integers are [5,6,7,...]. The 2^nd missing
 * positive integer is 6.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 1000
 * 1 <= arr[i] <= 1000
 * 1 <= k <= 1000
 * arr[i] < arr[j] for 1 <= i < j <= arr.length
 * 
 * 
 * 
 * Follow up:
 * 
 * Could you solve this problem in less than O(n) complexity?
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int missing(int actual, int expect) {
        return actual - expect;
    }
    int findKthPositive(vector<int>& arr, int k) {
        int head = 0;
        int tail = arr.size();
        while (head < tail) {
            int mid_idx = (head + tail) / 2;
            int mid_val = arr.at(mid_idx);
            int mid_missing = missing(mid_val, mid_idx + 1);
            if (mid_missing == k && mid_idx > 0) {
                
                int prev_idx = mid_idx - 1;
                int prev_val = arr.at(prev_idx);
                int prev_missing = missing(prev_val, prev_idx + 1);
                if (prev_missing < k) {
                    return prev_val + k - prev_missing;
                }
            }
            if (mid_missing >= k) {
                tail = mid_idx;
            } else {
                head = mid_idx + 1;
            }
        }
        if (tail == 0) {
            return k;
        }
        
        return arr.at(tail - 1) + k - missing(arr.at(tail - 1), tail);
    }// [2,3,4,7,11,12,13,14]\n5
    // [1,2,3,4]\n5
};
// @lc code=end

