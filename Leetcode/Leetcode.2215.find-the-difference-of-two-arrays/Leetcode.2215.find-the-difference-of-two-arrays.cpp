/*
 * @lc app=leetcode id=2215 lang=cpp
 *
 * [2215] Find the Difference of Two Arrays
 *
 * https://leetcode.com/problems/find-the-difference-of-two-arrays/description/
 *
 * algorithms
 * Easy (69.23%)
 * Likes:    648
 * Dislikes: 31
 * Total Accepted:    54.3K
 * Total Submissions: 76.4K
 * Testcase Example:  '[1,2,3]\n[2,4,6]'
 *
 * Given two 0-indexed integer arrays nums1 and nums2, return a list answer of
 * size 2 where:
 * 
 * 
 * answer[0] is a list of all distinct integers in nums1 which are not present
 * in nums2.
 * answer[1] is a list of all distinct integers in nums2 which are not present
 * in nums1.
 * 
 * 
 * Note that the integers in the lists may be returned in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums1 = [1,2,3], nums2 = [2,4,6]
 * Output: [[1,3],[4,6]]
 * Explanation:
 * For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1
 * and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
 * For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4
 * and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].
 * 
 * Example 2:
 * 
 * 
 * Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
 * Output: [[3],[]]
 * Explanation:
 * For nums1, nums1[2] and nums1[3] are not present in nums2. Since nums1[2] ==
 * nums1[3], their value is only included once and answer[0] = [3].
 * Every integer in nums2 is present in nums1. Therefore, answer[1] = [].
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums1.length, nums2.length <= 1000
 * -1000 <= nums1[i], nums2[i] <= 1000
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int s[2001];
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) { // Independently solved
        for (size_t i(0); i < 2001; ++i) { // The range of num in nums is very important!
            s[i] = 0;
        }
        for (int num : nums1) {
            size_t i(num + 1000);
            s[i] = 1;
        }
        for (int num : nums2) {
            size_t i(num + 1000);
            if (s[i] == 0) {
                s[i] = 2;
            } else if (s[i] == 1) {
                s[i] = 3;
            }
        }
        vector<vector<int>> ans(2);
        for (size_t i(0); i < 2001; ++i) {
            if (s[i] == 1) {
                ans.at(0).push_back(i - 1000);
            } else if (s[i] == 2) {
                ans.at(1).push_back(i - 1000);
            }
        }
        return ans;
    }
};
// @lc code=end

