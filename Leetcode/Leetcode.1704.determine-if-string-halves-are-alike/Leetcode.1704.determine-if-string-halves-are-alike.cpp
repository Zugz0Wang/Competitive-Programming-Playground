/*
 * @lc app=leetcode id=1704 lang=cpp
 *
 * [1704] Determine if String Halves Are Alike
 *
 * https://leetcode.com/problems/determine-if-string-halves-are-alike/description/
 *
 * algorithms
 * Easy (77.65%)
 * Likes:    698
 * Dislikes: 47
 * Total Accepted:    100.7K
 * Total Submissions: 130K
 * Testcase Example:  '"book"'
 *
 * You are given a string s of even length. Split this string into two halves
 * of equal lengths, and let a be the first half and b be the second half.
 * 
 * Two strings are alike if they have the same number of vowels ('a', 'e', 'i',
 * 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and
 * lowercase letters.
 * 
 * Return true if a and b are alike. Otherwise, return false.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "book"
 * Output: true
 * Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel.
 * Therefore, they are alike.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "textbook"
 * Output: false
 * Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2.
 * Therefore, they are not alike.
 * Notice that the vowel o is counted twice.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= s.length <= 1000
 * s.length is even.
 * s consists of uppercase and lowercase letters.
 * 
 * 
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    int index(char c) {
        if (c == 'a') {
            return 0;
        } else if (c == 'e') {
            return 1;
        } else if (c == 'i') {
            return 2;
        } else if (c == 'o') {
            return 3;
        } else if (c == 'u') {
            return 4;
        } else if (c == 'A') {
            return 0;
        } else if (c == 'E') {
            return 1;
        } else if (c == 'I') {
            return 2;
        } else if (c == 'O') {
            return 3;
        } else if (c == 'U') {
            return 4;
        }
        return -1;
    }

    bool halvesAreAlike(string s) {
        const int kLength = s.size();
        const int kHalf = kLength / 2;
        int count = 0;
        for (int i = 0; i < kHalf; i++) {
            int idx = index(s.at(i));
            if (idx >= 0) {
                count++;
            }
        }
        for (int i = kHalf; i < kLength; i++) {
            int idx = index(s.at(i));
            if (idx >= 0) {
               count--;
            }
        }
        if (count != 0) {
            return false;
        } else {
            return true;
        }
    }
};
// @lc code=end

