/*
 * @lc app=leetcode id=1218 lang=cpp
 *
 * [1218] Longest Arithmetic Subsequence of Given Difference
 *
 * https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/description/
 *
 * algorithms
 * Medium (51.84%)
 * Likes:    1944
 * Dislikes: 56
 * Total Accepted:    79.8K
 * Total Submissions: 149.8K
 * Testcase Example:  '[1,2,3,4]\n1'
 *
 * Given an integer array arr and an integer difference, return the length of
 * the longest subsequence in arr which is an arithmetic sequence such that the
 * difference between adjacent elements in the subsequence equals difference.
 * 
 * A subsequence is a sequence that can be derived from arr by deleting some or
 * no elements without changing the order of the remaining elements.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [1,2,3,4], difference = 1
 * Output: 4
 * Explanation: The longest arithmetic subsequence is [1,2,3,4].
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [1,3,5,7], difference = 1
 * Output: 1
 * Explanation: The longest arithmetic subsequence is any single element.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = [1,5,7,8,5,3,4,2,1], difference = -2
 * Output: 4
 * Explanation: The longest arithmetic subsequence is [7,5,3,1].
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 10^5
 * -10^4 <= arr[i], difference <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution { // Learned from solution; Busy
public:
    int longestSubsequence(vector<int>& nums, int difference) {
        map<int, int> m;
        const size_t size(nums.size());
        int ans(1);
        for (size_t i(0); i < size; ++i) {
            int num(nums.at(i));
            int prev(num - difference);
            int count(1);
            if (m.count(prev) > 0) {
                count = m.at(prev) + 1;
            }
            
            m[num] = count;
            
            if (count > ans) {
                ans = count;
            }
        }
        return ans;
    }
};
// @lc code=end

