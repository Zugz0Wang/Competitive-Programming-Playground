/*
 * @lc app=leetcode id=1187 lang=cpp
 *
 * [1187] Make Array Strictly Increasing
 *
 * https://leetcode.com/problems/make-array-strictly-increasing/description/
 *
 * algorithms
 * Hard (45.04%)
 * Likes:    1433
 * Dislikes: 26
 * Total Accepted:    28.6K
 * Total Submissions: 52.5K
 * Testcase Example:  '[1,5,3,6,7]\n[1,3,2,4]'
 *
 * Given two integer arrays arr1 and arr2, return the minimum number of
 * operations (possibly zero) needed to make arr1 strictly increasing.
 * 
 * In one operation, you can choose two indices 0 <= i < arr1.length and 0 <= j
 * < arr2.length and do the assignment arr1[i] = arr2[j].
 * 
 * If there is no way to make arr1 strictly increasing, return -1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
 * Output: 1
 * Explanation: Replace 5 with 2, then arr1 = [1, 2, 3, 6, 7].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr1 = [1,5,3,6,7], arr2 = [4,3,1]
 * Output: 2
 * Explanation: Replace 5 with 3 and then replace 3 with 4. arr1 = [1, 3, 4, 6,
 * 7].
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
 * Output: -1
 * Explanation: You can't make arr1 strictly increasing.
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr1.length, arr2.length <= 2000
 * 0 <= arr1[i], arr2[i] <= 10^9
 * 
 * 
 * 
 */

// @lc code=start
class Solution { // Learned from solution
public:
    vector<int> arr1;
    vector<int> arr2;
    vector<vector<int>> dp;
    size_t size1;
    size_t size2;
    const int m = 2001;
    int helper(size_t i0, size_t i1, int prev) {
        if (i0 >= size1) return 0;
        bool take(false);
        int replace(0);
        int if_take(m);
        int if_pass(m);
        for (; i1 < size2; ++i1) {
            if (arr2.at(i1) > prev) {
                replace = arr2.at(i1);   
                take = true;
                break;
            }
        }

        int& curr(dp.at(i0).at(i1)); // After the upperbound part
        if (curr > -1) {
            return curr;
        }
        
        if (take) {
            if_take = helper(i0 + 1, i1 + 1, arr2.at(i1)) + 1;
        }

        if (arr1.at(i0) > prev) {
            if_pass = helper(i0 + 1, i1, arr1.at(i0));
        }
        
        if (if_take < if_pass) {
            curr = if_take;
        } else {
            curr = if_pass;
        }

        return curr;
    }

    int makeArrayIncreasing(vector<int>& arr1_, vector<int>& arr2_) {
        arr1 = arr1_;
        arr2 = arr2_;
        size1 = arr1.size();
        size2 = arr2.size();
        sort(arr2.begin(), arr2.end());
        dp.resize(size1 + 1);
        for (size_t i(0); i < size1; ++i) {
            dp.at(i).resize(size2 + 1, -2);
        }
        int result(helper(0, 0, -1));
        if (result == m) {
            result = -1;
        }
        return result;
    }
};
// @lc code=end

