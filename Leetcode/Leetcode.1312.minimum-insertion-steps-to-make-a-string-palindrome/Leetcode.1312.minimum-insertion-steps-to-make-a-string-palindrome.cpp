/*
 * @lc app=leetcode id=1312 lang=cpp
 *
 * [1312] Minimum Insertion Steps to Make a String Palindrome
 *
 * https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/
 *
 * algorithms
 * Hard (65.10%)
 * Likes:    3196
 * Dislikes: 38
 * Total Accepted:    80.4K
 * Total Submissions: 120.5K
 * Testcase Example:  '"zzazz"'
 *
 * Given a string s. In one step you can insert any character at any index of
 * the string.
 * 
 * Return the minimum number of steps to make s palindrome.
 * 
 * A Palindrome String is one that reads the same backward as well as
 * forward.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "zzazz"
 * Output: 0
 * Explanation: The string "zzazz" is already palindrome we do not need any
 * insertions.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "mbadm"
 * Output: 2
 * Explanation: String can be "mbdadbm" or "mdbabdm".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "leetcode"
 * Output: 5
 * Explanation: Inserting 5 characters the string becomes "leetcodocteel".
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 500
 * s consists of lowercase English letters.
 * 
 * 
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> dp;
    string s;
    int dfs(size_t first, size_t last) { // Top down memorization
        if (first >= last) {
            return 0;
        }
        int& curr(dp.at(first).at(last));
        if (curr != -1) {
            return curr;
        }

        if (s.at(first) == s.at(last)) {
            if ((last + 1 - first) > 2) {
                curr = dfs(first + 1, last - 1);
            } else {
                curr = 0;
            }
        } else {
            curr = 1 + min(dfs(first, last - 1), dfs(first + 1, last));
        }
        return curr;
    }

    int minInsertions(string s_) {
        s = s_;
        const size_t length(s.size());
       
        dp.resize(length, vector<int>(length ,-1));
       
        // for (size_t l(2); l <= length; ++l) { bottom up
        //     for (size_t begin(0); begin <= length - l; ++begin) {
        //         const size_t last(begin + l - 1);
        //         int& curr(dp.at(begin).at(last));
        //         if (s.at(begin) == s.at(last)) {
        //             if (length > 2) {
        //                 curr = dp.at(begin + 1).at(last - 1);
        //             } 
        //         } else {
        //             curr = 1 + min(dp.at(begin).at(last - 1), dp.at(begin + 1).at(last));
        //         }
        //     }
        // }

        return dfs(0, length - 1);
    }
};
// @lc code=end

