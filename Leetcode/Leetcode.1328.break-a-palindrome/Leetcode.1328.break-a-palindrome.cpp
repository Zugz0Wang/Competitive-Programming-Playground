/*
 * @lc app=leetcode id=1328 lang=cpp
 *
 * [1328] Break a Palindrome
 *
 * https://leetcode.com/problems/break-a-palindrome/description/
 *
 * algorithms
 * Medium (52.16%)
 * Likes:    872
 * Dislikes: 470
 * Total Accepted:    78.2K
 * Total Submissions: 150.9K
 * Testcase Example:  '"abccba"'
 *
 * Given a palindromic string of lowercase English letters palindrome, replace
 * exactly one character with any lowercase English letter so that the
 * resulting string is not a palindrome and that it is the lexicographically
 * smallest one possible.
 * 
 * Return the resulting string. If there is no way to replace a character to
 * make it not a palindrome, return an empty string.
 * 
 * A string a is lexicographically smaller than a string b (of the same length)
 * if in the first position where a and b differ, a has a character strictly
 * smaller than the corresponding character in b. For example, "abcc" is
 * lexicographically smaller than "abcd" because the first position they differ
 * is at the fourth character, and 'c' is smaller than 'd'.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: palindrome = "abccba"
 * Output: "aaccba"
 * Explanation: There are many ways to make "abccba" not a palindrome, such as
 * "zbccba", "aaccba", and "abacba".
 * Of all the ways, "aaccba" is the lexicographically smallest.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: palindrome = "a"
 * Output: ""
 * Explanation: There is no way to replace a single character to make "a" not a
 * palindrome, so return an empty string.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= palindrome.length <= 1000
 * palindrome consists of only lowercase English letters.
 * 
 * 
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    string breakPalindrome(string palindrome) {
        const int kLength = palindrome.length();
        if (kLength == 1) {
            return "";
        }
        for (int i = 0; i < kLength / 2; i++) {
            if (palindrome.at(i) != 'a') {
                palindrome.at(i) = 'a';
                return palindrome;
            }
        }
        palindrome.at(kLength - 1) = 'b';
        return palindrome;
    }
};
// @lc code=end

