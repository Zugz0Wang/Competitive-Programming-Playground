/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 *
 * https://leetcode.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (28.26%)
 * Likes:    8984
 * Dislikes: 1399
 * Total Accepted:    724.8K
 * Total Submissions: 2.6M
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string s and a pattern p, implement regular expression
 * matching with support for '.' and '*' where:
 * 
 * 
 * '.' Matches any single character.​​​​
 * '*' Matches zero or more of the preceding element.
 * 
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "aa", p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "aa", p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the preceding element, 'a'.
 * Therefore, by repeating 'a' once, it becomes "aa".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "ab", p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 20
 * 1 <= p.length <= 30
 * s contains only lowercase English letters.
 * p contains only lowercase English letters, '.', and '*'.
 * It is guaranteed for each appearance of the character '*', there will be a
 * previous valid character to match.
 * 
 * '"aasdfasdfasdfasdfas"\n"aasdf.*asdf.*asdf.*asdf.*s"'
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        const int sLength = s.length() + 1;
        const int pLength = p.length() + 1;
        vector<bool> asterisk(pLength, false);
        string r;
        int offset = 1;
        for (int i = 0; i < pLength - 1; i++) {
            char curr_char = p.at(i);
            if (curr_char == '*') {
                if (p.at(i - 1) != '*') {
                    asterisk.at(i - offset) = true;
                }
                // cout << i - offset << ' ';
                offset++;
            } else {
                r += curr_char;
            }
        } 
        // cout << '\n';
        const int rLength = r.length() + 1;
        vector<bool> row(rLength, false);
        vector<vector<bool>> dp_table(sLength, row);
        
        dp_table.at(0).at(0) = true;
        for (int j = 1; j < rLength; j++) {
            if (asterisk.at(j - 1)) {
                dp_table.at(0).at(j) = true;
            } else {
                break;
            }
        }
        for (int i = 1; i < sLength; i++) {
            for (int j = 1; j < rLength; j++) {
                char s_char = s.at(i - 1);
                char r_char = r.at(j - 1);
                bool curr_state = false;
                if (asterisk.at(j - 1)) {
                    if (r_char == '.' || r_char == s_char) {
                        // cout << "Case0: " << i << ' ' << j << '\n';
                        curr_state = dp_table.at(i - 1).at(j) || dp_table.at(i - 1).at(j - 1) || dp_table.at(i).at(j - 1);
                    } else {
                        // cout << "Case1: " << i << ' ' << j << '\n';
                        curr_state = dp_table.at(i).at(j - 1);
                    }
                } else if (r_char == '.') {
                    curr_state = dp_table.at(i - 1).at(j - 1);
                } else if (r_char == s_char) {
                    curr_state = dp_table.at(i - 1).at(j - 1);
                }
                
                if (curr_state) {
                    dp_table.at(i).at(j) = true;
                }
            }
            
        }
        // for (int i = 0; i < sLength; i++) {
        //     for (int j = 0; j < rLength; j++) {
        //         cout << dp_table.at(i).at(j) << ' ';
        //     }
        //     cout << '\n';
        // }
        return dp_table.at(sLength - 1).at(rLength - 1);
    }
};
// @lc code=end
// Debugging
//     a a s d f . a s d f . a s d f . a s d f . s
//   1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
// a 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
// a 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
// s 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
// d 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
// f 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
// a 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
// s 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
// d 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
// f 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
// a 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
// s 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
// d 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 
// f 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 
// a 0 0 0 0 0 0 1 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 
// s 0 0 0 0 0 0 1 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 
// d 0 0 0 0 0 0 1 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 
// f 0 0 0 0 0 0 1 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 
// a 0 0 0 0 0 0 1 1 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 
// s 0 0 0 0 0 0 1 0 1 0 0 1 0 1 0 0 0 0 0 0 0 0 0 


