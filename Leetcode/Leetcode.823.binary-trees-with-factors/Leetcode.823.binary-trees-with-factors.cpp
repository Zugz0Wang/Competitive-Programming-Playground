/*
 * @lc app=leetcode id=823 lang=cpp
 *
 * [823] Binary Trees With Factors
 *
 * https://leetcode.com/problems/binary-trees-with-factors/description/
 *
 * algorithms
 * Medium (50.09%)
 * Likes:    2367
 * Dislikes: 172
 * Total Accepted:    84.6K
 * Total Submissions: 168.9K
 * Testcase Example:  '[2,4]'
 *
 * Given an array of unique integers, arr, where each integer arr[i] is
 * strictly greater than 1.
 * 
 * We make a binary tree using these integers, and each number may be used for
 * any number of times. Each non-leaf node's value should be equal to the
 * product of the values of its children.
 * 
 * Return the number of binary trees we can make. The answer may be too large
 * so return the answer modulo 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [2,4]
 * Output: 3
 * Explanation: We can make these trees: [2], [4], [4, 2, 2]
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [2,4,5,10]
 * Output: 7
 * Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10,
 * 2, 5], [10, 5, 2].
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 1000
 * 2 <= arr[i] <= 10^9
 * All the values of arr are unique.
 * 
 * 
 */
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    const int kMod = 1e9 + 7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int kSize = arr.size();
        sort(begin(arr), end(arr));
        unordered_map<int, long> dp;
        long sum = 0;
        for (int i = 0; i < kSize; i++) {
            int curr = arr.at(i);
            long total = 1;
            dp.insert(pair<int, long>(curr, 1));
            for (int idx_j = 0; idx_j < i; idx_j++) {
                int j = arr.at(idx_j);
                int k = curr / j;
                if (curr % j == 0 && dp.count(k) > 0) {
                    total += dp.at(k) * dp.at(j);
                }
            }
            dp.at(curr) = total;
            sum += total;
        }
        return sum % (int)kMod;
    }
};
// @lc code=end

