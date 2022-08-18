/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 *
 * https://leetcode.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (47.35%)
 * Likes:    1791
 * Dislikes: 1952
 * Total Accepted:    371.8K
 * Total Submissions: 785K
 * Testcase Example:  '"hello"'
 *
 * Given a string s, reverse only all the vowels in the string and return it.
 * 
 * The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both
 * cases.
 * 
 * 
 * Example 1:
 * Input: s = "hello"
 * Output: "holle"
 * Example 2:
 * Input: s = "leetcode"
 * Output: "leotcede"
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 3 * 10^5
 * s consist of printable ASCII characters.
 * 
 * 
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    string reverseVowels(string s) {
        const int kLength = s.length();
        

        int head = 0;
        int tail = kLength - 1;
        bool left_found = false;
        bool right_found = false;
        while (head < tail) {
            if (!left_found && isVowel(s.at(head))) {
                left_found = true;
            } else if (!left_found) {
                head++;
            }

            if (!right_found && isVowel(s.at(tail))) {
                right_found = true;
            } else if (!right_found) {
                tail--;
            }
            
            if (left_found && right_found) {
                swap(s[head], s[tail]);
                left_found = false;
                right_found = false;
                head++;
                tail--;
            }
        }
        
        return s;
    }
};
// @lc code=end

