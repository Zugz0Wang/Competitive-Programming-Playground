/*
 * @lc app=leetcode id=1346 lang=cpp
 *
 * [1346] Check If N and Its Double Exist
 *
 * https://leetcode.com/problems/check-if-n-and-its-double-exist/description/
 *
 * algorithms
 * Easy (35.85%)
 * Likes:    1417
 * Dislikes: 158
 * Total Accepted:    259.1K
 * Total Submissions: 712.8K
 * Testcase Example:  '[10,2,5,3]'
 *
 * Given an array arr of integers, check if there exist two indices i and j
 * such that :
 * 
 * 
 * i != j
 * 0 <= i, j < arr.length
 * arr[i] == 2 * arr[j]
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [10,2,5,3]
 * Output: true
 * Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [3,1,7,11]
 * Output: false
 * Explanation: There is no i and j that satisfy the conditions.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= arr.length <= 500
 * -10^3 <= arr[i] <= 10^3
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        const int kSize = arr.size();
        for (int i = 0; i < kSize; i++) {
            int head = i + 1;
            int tail = kSize;
            int curr = arr.at(i);
            if (curr < 0) {
                head = 0;
                tail = i;
            }
            int target = curr * 2;
            while (head < tail) {
                int mid_idx = (head + tail) / 2;
                int mid_val = arr.at(mid_idx);
                if (mid_val == target) {
                    return true;
                } else if (mid_val < target) {
                    head = mid_idx + 1;
                } else {
                    tail = mid_idx;
                }
            }
        }
        return false;
    } // [-10,12,-20,-8,15]
};
// @lc code=end

