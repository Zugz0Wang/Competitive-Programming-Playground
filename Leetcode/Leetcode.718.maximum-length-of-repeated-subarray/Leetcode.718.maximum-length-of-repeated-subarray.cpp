/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 *
 * https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/
 *
 * algorithms
 * Medium (51.46%)
 * Likes:    5526
 * Dislikes: 139
 * Total Accepted:    235.8K
 * Total Submissions: 456.1K
 * Testcase Example:  '[1,2,3,2,1]\n[3,2,1,4,7]'
 *
 * Given two integer arrays nums1 and nums2, return the maximum length of a
 * subarray that appears in both arrays.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
 * Output: 3
 * Explanation: The repeated subarray with maximum length is [3,2,1].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
 * Output: 5
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums1.length, nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 100
 * 
 * 
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int dp[1001][1001];
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, 0, sizeof(dp));
        const int kM = nums1.size();
        const int kN = nums2.size();
        int ans = 0;
        for (int i = 1; i <= kM; i++) {
            for (int j = 1; j <= kN; j++) {
                if (nums1.at(i - 1) == nums2.at(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = 0;
                }
                if (ans < dp[i][j]) {
                    ans = dp[i][j];
                }
            }
        }
        return ans;
    }
};
// @lc code=end

