/*
 * @lc app=leetcode id=1855 lang=cpp
 *
 * [1855] Maximum Distance Between a Pair of Values
 *
 * https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/description/
 *
 * algorithms
 * Medium (52.21%)
 * Likes:    947
 * Dislikes: 22
 * Total Accepted:    37.2K
 * Total Submissions: 70.4K
 * Testcase Example:  '[55,30,5,4,2]\n[100,20,10,10,5]'
 *
 * You are given two non-increasing 0-indexed integer arrays nums1​​​​​​ and
 * nums2​​​​​​.
 * 
 * A pair of indices (i, j), where 0 <= i < nums1.length and 0 <= j <
 * nums2.length, is valid if both i <= j and nums1[i] <= nums2[j]. The distance
 * of the pair is j - i​​​​.
 * 
 * Return the maximum distance of any valid pair (i, j). If there are no valid
 * pairs, return 0.
 * 
 * An array arr is non-increasing if arr[i-1] >= arr[i] for every 1 <= i <
 * arr.length.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums1 = [55,30,5,4,2], nums2 = [100,20,10,10,5]
 * Output: 2
 * Explanation: The valid pairs are (0,0), (2,2), (2,3), (2,4), (3,3), (3,4),
 * and (4,4).
 * The maximum distance is 2 with pair (2,4).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums1 = [2,2,2], nums2 = [10,10,1]
 * Output: 1
 * Explanation: The valid pairs are (0,0), (0,1), and (1,1).
 * The maximum distance is 1 with pair (0,1).
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums1 = [30,29,19,5], nums2 = [25,25,25,25,25]
 * Output: 2
 * Explanation: The valid pairs are (2,2), (2,3), (2,4), (3,3), and (3,4).
 * The maximum distance is 2 with pair (2,4).
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums1.length, nums2.length <= 10^5
 * 1 <= nums1[i], nums2[j] <= 10^5
 * Both nums1 and nums2 are non-increasing.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        const int kSize1 = nums1.size();
        const int kSize2 = nums2.size();
        int max = 0;
        for (int i = 0; i < kSize1; i++) {
            int target = nums1.at(i);
            int head = i;
            int tail = kSize2;
            while (head < tail) {
                int mid_idx = (head + tail) / 2;
                int mid_val = nums2.at(mid_idx);
                if (mid_val >= target) {
                    head = mid_idx + 1;
                } else {
                    tail = mid_idx;
                }
            }
            int dis = tail - 1 - i;
            if (dis > max) {
                max = dis;
            }
        }
        return max;
    }
    // [30,29,19,5]\n[25,25,25,25,25]
};
// @lc code=end

