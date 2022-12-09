/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 *
 * https://leetcode.com/problems/sort-characters-by-frequency/description/
 *
 * algorithms
 * Medium (68.24%)
 * Likes:    5239
 * Dislikes: 204
 * Total Accepted:    418.1K
 * Total Submissions: 608.1K
 * Testcase Example:  '"tree"'
 *
 * Given a string s, sort it in decreasing order based on the frequency of the
 * characters. The frequency of a character is the number of times it appears
 * in the string.
 * 
 * Return the sorted string. If there are multiple answers, return any of
 * them.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "tree"
 * Output: "eert"
 * Explanation: 'e' appears twice while 'r' and 't' both appear once.
 * So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid
 * answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "cccaaa"
 * Output: "aaaccc"
 * Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and
 * "aaaccc" are valid answers.
 * Note that "cacaca" is incorrect, as the same characters must be together.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "Aabb"
 * Output: "bbAa"
 * Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
 * Note that 'A' and 'a' are treated as two different characters.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 5 * 10^5
 * s consists of uppercase and lowercase English letters and digits.
 * 
 * 
 */
#include <string>
#include <map>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int count[62];
    int index(char c) {
        if (c >= '0' && '9' >= c) {
            return c - '0';
        } else if (c >= 'a' && c <= 'z') {
            return 10 + c - 'a';
        } else if (c >= 'A' && c <= 'Z') {
            return 36 + c - 'A';
        }
        return -1;
    }
    char reverse(int n) {
        if (n >= 0 && n < 10) {
            return '0' + n;
        } else if (n >= 10 && n < 36) {
            return 'a' + n - 10;
        } else if (n >= 36 && n < 62) {
            return 'A' + n - 36;
        }
        return '!';
    }
    string frequencySort(string s) {
        memset(count, 0, sizeof(count));
        for (char c : s) { 
            count[index(c)]++;
        }
        map<int, string> mp;
        for (int i = 0; i < 62; i++) {
            int curr = count[i];
            if (curr > 0) {
                cout << reverse(i) << '\n';
                char curr_char = reverse(i);
                if (mp.count(curr) == 0) {
                    mp.insert(pair<int, string>(curr, ""));
                }
                mp.at(curr) += string(curr, reverse(i));
            }
        }
        string ans;
        for (auto p = mp.rbegin(); p != mp.rend(); p++) {
            ans += p->second;
        }
        return ans;
    }
};
// @lc code=end

