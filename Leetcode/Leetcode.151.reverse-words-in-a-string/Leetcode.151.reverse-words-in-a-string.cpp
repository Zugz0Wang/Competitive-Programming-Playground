/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 *
 * https://leetcode.com/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (29.53%)
 * Likes:    4303
 * Dislikes: 4230
 * Total Accepted:    794.6K
 * Total Submissions: 2.6M
 * Testcase Example:  '"the sky is blue"'
 *
 * Given an input string s, reverse the order of the words.
 * 
 * A word is defined as a sequence of non-space characters. The words in s will
 * be separated by at least one space.
 * 
 * Return a string of the words in reverse order concatenated by a single
 * space.
 * 
 * Note that s may contain leading or trailing spaces or multiple spaces
 * between two words. The returned string should only have a single space
 * separating the words. Do not include any extra spaces.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "the sky is blue"
 * Output: "blue is sky the"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "  hello world  "
 * Output: "world hello"
 * Explanation: Your reversed string should not contain leading or trailing
 * spaces.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "a good   example"
 * Output: "example good a"
 * Explanation: You need to reduce multiple spaces between two words to a
 * single space in the reversed string.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^4
 * s contains English letters (upper-case and lower-case), digits, and spaces '
 * '.
 * There is at least one word in s.
 * 
 * 
 * 
 * Follow-up: If the string data type is mutable in your language, can you
 * solve it in-place with O(1) extra space?
 * 
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        int length = s.length();
        int head = 0;
        int tail = length - 1;
        while (s.at(head) == ' ') {
            head++;
        }
        while (s.at(tail) == ' ') {
            tail--;
        }
        s = s.substr(head, tail - head + 1);
        length = s.length();
        head = 0;
        tail = length - 1;
        while (head < tail) {
            char temp = s.at(head);
            s.at(head) = s.at(tail);
            s.at(tail) = temp;
            head++;
            tail--;
        }
        int pion = 0;
        while (pion < length) {
            head = pion;
            while (pion < length && s.at(pion) != ' ') {
                pion++;
            }
            tail = pion - 1;
            while (head < tail) {
                char temp = s.at(head);
                s.at(head) = s.at(tail);
                s.at(tail) = temp;
                head++;
                tail--;
            }
            while (pion < length && s.at(pion) == ' ') {
                pion++;
            }
        }
        head = 0; pion = 0;
        while (pion < length) {
            if (s.at(pion) != ' ') {
                s.at(head) = s.at(pion);
                head++;
                pion++;
            } else {
                pion++;
                s.at(head) = ' ';
                head++;
                while (pion < length && s.at(pion) == ' ') {
                    pion++;
                }
            }
        }
        return s.substr(0,head);
    } 
};
// @lc code=end

