/*
 * @lc app=leetcode id=1071 lang=cpp
 *
 * [1071] Greatest Common Divisor of Strings
 *
 * https://leetcode.com/problems/greatest-common-divisor-of-strings/description/
 *
 * algorithms
 * Easy (51.14%)
 * Likes:    1620
 * Dislikes: 320
 * Total Accepted:    89.1K
 * Total Submissions: 173.7K
 * Testcase Example:  '"ABCABC"\n"ABC"'
 *
 * For two strings s and t, we say "t divides s" if and only if s = t + ... + t
 * (i.e., t is concatenated with itself one or more times).
 * 
 * Given two strings str1 and str2, return the largest string x such that x
 * divides both str1 and str2.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: str1 = "ABCABC", str2 = "ABC"
 * Output: "ABC"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: str1 = "ABABAB", str2 = "ABAB"
 * Output: "AB"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: str1 = "LEET", str2 = "CODE"
 * Output: ""
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= str1.length, str2.length <= 1000
 * str1 and str2 consist of English uppercase letters.
 * 
 * 
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        const int kSize1 = str1.size();
        const int kSize2 = str2.size();
        int x = 0;
        if (kSize1 < kSize2) {
            x = kSize1;
        } else {
            x = kSize2;
        }
        while (x > 0) {
            if (kSize1 % x == 0 && kSize2 % x == 0) {
                string curr_x = str1.substr(0, x);
                bool check = true;
                for (int i = x; i + x <= kSize1; i += x) {
                    if (curr_x != str1.substr(i, x)) {
                        check = false;
                        break;
                    }
                }
                for (int i = 0; i + x <= kSize2; i += x) {
                    if (curr_x != str2.substr(i, x)) {
                        check = false;
                        break;
                    }
                }
                if (check) {
                    return curr_x;
                }
            }
            x--;
        }
        return "";
    }
};
//'"ABABAB"\n"ABAB"'
//'"ABABAB"\n"ACAB"'
// @lc code=end

