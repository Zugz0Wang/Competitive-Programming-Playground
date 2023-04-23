/*
 * @lc app=leetcode id=1416 lang=cpp
 *
 * [1416] Restore The Array
 *
 * https://leetcode.com/problems/restore-the-array/description/
 *
 * algorithms
 * Hard (38.10%)
 * Likes:    497
 * Dislikes: 22
 * Total Accepted:    15.8K
 * Total Submissions: 40K
 * Testcase Example:  '"1000"\n10000'
 *
 * A program was supposed to print an array of integers. The program forgot to
 * print whitespaces and the array is printed as a string of digits s and all
 * we know is that all integers in the array were in the range [1, k] and there
 * are no leading zeros in the array.
 * 
 * Given the string s and the integer k, return the number of the possible
 * arrays that can be printed as s using the mentioned program. Since the
 * answer may be very large, return it modulo 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "1000", k = 10000
 * Output: 1
 * Explanation: The only possible array is [1000]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "1000", k = 10
 * Output: 0
 * Explanation: There cannot be an array that was printed this way and has all
 * integer >= 1 and <= 10.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "1317", k = 2000
 * Output: 8
 * Explanation: Possible arrays are
 * [1317],[131,7],[13,17],[1,317],[13,1,7],[1,31,7],[1,3,17],[1,3,1,7]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s consists of only digits and does not contain leading zeros.
 * 1 <= k <= 10^9
 * 
 * 
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> dp;
    string s;
    int k;
    int mod = (1e9 + 7);
    int dfs(size_t i) {
       
        if (dp.at(i) >= 0) {
            return dp.at(i);
        }
        if (s.at(i) == '0') {
            dp.at(i) = 0;
            return 0;
        }

        unsigned long curr(s.at(i) - '0');
        size_t next(i + 1);
        int ans(0);
        while (curr <= k && next < s.size()) {
            curr *= 10;
            curr += s.at(next) - '0';
            // if (i == 0) {
            //     cout << curr << '\n';
            // }
            ans += dfs(next);
            ans %= mod;
            ++next;
        }
        if (next >= s.size() && curr <= k) {
            ans += 1;
        }
        dp.at(i) = ans % mod;
        return dp.at(i);
    }

    int numberOfArrays(string s_, int k_) {
        k = k_;
        s = s_;
        const size_t s_size(s.size());
        dp.resize(s_size, -1);
        return dfs(0);
    }
};
// @lc code=end

