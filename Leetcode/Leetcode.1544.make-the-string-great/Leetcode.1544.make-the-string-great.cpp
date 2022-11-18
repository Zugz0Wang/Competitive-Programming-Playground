/*
 * @lc app=leetcode id=1544 lang=cpp
 *
 * [1544] Make The String Great
 *
 * https://leetcode.com/problems/make-the-string-great/description/
 *
 * algorithms
 * Easy (56.76%)
 * Likes:    879
 * Dislikes: 57
 * Total Accepted:    59.5K
 * Total Submissions: 103.9K
 * Testcase Example:  '"leEeetcode"'
 *
 * Given a string s of lower and upper case English letters.
 * 
 * A good string is a string which doesn't have two adjacent characters s[i]
 * and s[i + 1] where:
 * 
 * 
 * 0 <= i <= s.length - 2
 * s[i] is a lower-case letter and s[i + 1] is the same letter but in
 * upper-case or vice-versa.
 * 
 * 
 * To make the string good, you can choose two adjacent characters that make
 * the string bad and remove them. You can keep doing this until the string
 * becomes good.
 * 
 * Return the string after making it good. The answer is guaranteed to be
 * unique under the given constraints.
 * 
 * Notice that an empty string is also good.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "leEeetcode"
 * Output: "leetcode"
 * Explanation: In the first step, either you choose i = 1 or i = 2, both will
 * result "leEeetcode" to be reduced to "leetcode".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "abBAcC"
 * Output: ""
 * Explanation: We have many possible scenarios, and all lead to the same
 * answer. For example:
 * "abBAcC" --> "aAcC" --> "cC" --> ""
 * "abBAcC" --> "abBA" --> "aA" --> ""
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "s"
 * Output: "s"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 100
 * s contains only lower and upper case English letters.
 * 
 * 
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    // string makeGood(string s) {
    //     int length = s.length();
    //     int i = 0;
    //     int prev_idx = -1;
    //     while (i < length) {
    //         if (prev_idx >= 0) {
    //             char curr = s.at(i);
    //             char next = s.at(prev_idx);
    //             if (curr + 32 == next || curr - 32 == next) {
    //                 prev_idx -= 1;
    //             } else {
    //                 s.at(prev_idx + 1) = s.at(i);
    //                 prev_idx++;
    //             }
    //         } else {
    //             s.at(prev_idx + 1) = s.at(i);
    //             prev_idx++;
    //         }
    //         i++;
    //     }
    //     return s.substr(0,prev_idx + 1);
    // }
    string makeGood(string s) {
        int length = s.length();
        int i = 0;
        while (i < length - 1) {
            char curr = s.at(i);
            char next = s.at(i + 1);
            if (curr + 32 == next || curr - 32 == next) {
                if (i + 2 < length) {
                    s = s.substr(0, i) + s.substr(i + 2, length - i - 2);
                } else {
                    s = s.substr(0, i);
                }
                if (i > 0) {
                    i--;
                }
                length -= 2;
            } else {
                i++;
            }
        }
        return s;
    }
};
// @lc code=end

