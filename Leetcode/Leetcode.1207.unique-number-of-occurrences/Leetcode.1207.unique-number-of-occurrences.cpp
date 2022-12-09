/*
 * @lc app=leetcode id=1207 lang=cpp
 *
 * [1207] Unique Number of Occurrences
 *
 * https://leetcode.com/problems/unique-number-of-occurrences/description/
 *
 * algorithms
 * Easy (71.52%)
 * Likes:    2272
 * Dislikes: 51
 * Total Accepted:    180.4K
 * Total Submissions: 253.4K
 * Testcase Example:  '[1,2,2,1,1,3]'
 *
 * Given an array of integers arr, return true if the number of occurrences of
 * each value in the array is unique, or false otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [1,2,2,1,1,3]
 * Output: true
 * Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two
 * values have the same number of occurrences.
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [1,2]
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
 * Output: true
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 1000
 * -1000 <= arr[i] <= 1000
 * 
 * 
 */
#include <vector>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    int count[2001];
    bool uniqueOccurrences(vector<int>& arr) {
        memset(count, 0, sizeof(count));
        for (int num : arr) {
            int idx = num + 1000;
            count[idx] = count[idx] + 1;
        }
        unordered_set<int> st;
        for (int i = 0; i < 2001; i++) {
            int curr = count[i];
            if (curr > 0) {
                if (st.count(curr) != 0) {
                    return false;
                } else {
                    st.insert(curr);
                }
            }
        }
        return true;
    }
};
// @lc code=end

