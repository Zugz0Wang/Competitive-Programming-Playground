/*
 * @lc app=leetcode id=1802 lang=cpp
 *
 * [1802] Maximum Value at a Given Index in a Bounded Array
 *
 * https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/description/
 *
 * algorithms
 * Medium (31.40%)
 * Likes:    880
 * Dislikes: 156
 * Total Accepted:    18.9K
 * Total Submissions: 56K
 * Testcase Example:  '4\n2\n6'
 *
 * You are given three positive integers: n, index, and maxSum. You want to
 * construct an array nums (0-indexed) that satisfies the following
 * conditions:
 * 
 * 
 * nums.length == n
 * nums[i] is a positive integer where 0 <= i < n.
 * abs(nums[i] - nums[i+1]) <= 1 where 0 <= i < n-1.
 * The sum of all the elements of nums does not exceed maxSum.
 * nums[index] is maximized.
 * 
 * 
 * Return nums[index] of the constructed array.
 * 
 * Note that abs(x) equals x if x >= 0, and -x otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 4, index = 2,  maxSum = 6
 * Output: 2
 * Explanation: nums = [1,2,2,1] is one array that satisfies all the
 * conditions.
 * There are no arrays that satisfy all the conditions and have nums[2] == 3,
 * so 2 is the maximum nums[2].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 6, index = 1,  maxSum = 10
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= maxSum <= 10^9
 * 0 <= index < n
 * 
 * 
 */

// @lc code=start
class Solution { // Independently solved
public:
    size_t left;
    size_t right;

    long sumHelper(int start, int length) {

        long sum(0);
        int l(length);
        if (start < length) {
            sum += length - start;
            l = start;
        }
        int end(start - l + 1);
        sum += ((long)start + end) * (l) / 2;
        return sum;
    }

   
    int maxValue(int n, int index, int maxSum) {
        left = index;
        right = n - 1 - index;
        int head(1);
        int last(maxSum + 1);
        
        while (head < last) {
           int mid((head + last) / 2);
           const int start(mid - 1);
           long mid_val((long)mid + sumHelper(start, left) + sumHelper(start, right));
        //    cout << mid << ": " << mid_val << ' ' << sumHelper(start, left) << ' ' << sumHelper(start, right) << '\n';
           if (mid_val == (long)maxSum) {
               return mid;
           } else if (mid_val < maxSum) {
               head = mid + 1;
           } else {
               last = mid;
           }
        }
        return head - 1;
    }
};
// @lc code=end

