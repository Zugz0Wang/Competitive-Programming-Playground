/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 *
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (48.76%)
 * Likes:    9653
 * Dislikes: 294
 * Total Accepted:    668.7K
 * Total Submissions: 1.4M
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * Given two strings s and p, return an array of all the start indices of p's
 * anagrams in s. You may return the answer in any order.
 * 
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "cbaebabacd", p = "abc"
 * Output: [0,6]
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of "abc".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "abab", p = "ab"
 * Output: [0,1,2]
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length, p.length <= 3 * 10^4
 * s and p consist of lowercase English letters.
 * 
 * 
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public: // Original Solution
    int count[26];
    vector<int> findAnagrams(string s2, string s1) {
        vector<int> ans;
        memset(count, 0, sizeof(count));
        const int kSize1 = s1.size();
        const int kSize2 = s2.size();
        if (kSize1 > kSize2) {
            return ans;
        }
        for (int i = 0; i < kSize1; i++) {
            count[s1.at(i) - 'a'] += 1;
            count[s2.at(i) - 'a'] -= 1;
        }
        int unsatisfy = 0;
        for (int c = 0; c < 26; c++) {
            if (count[c] != 0) {
                unsatisfy += 1;
            }
        }
        for (int i = 0; i <= kSize2 - kSize1; i++) {
            // cout << satisfy << ' ';
            if (unsatisfy == 0) {
                ans.push_back(i);
            } 
            if (i + kSize1 < kSize2) {
                int idx1 = s2.at(i) - 'a';
                int idx2 = s2.at(i + kSize1) - 'a';
                if (count[idx1] == 0) {
                    unsatisfy += 1;
                }
                if (count[idx2] == 0) {
                    unsatisfy += 1;
                }
                count[idx1] += 1;
                count[idx2] -= 1;
                if (count[idx1] == 0) {
                    unsatisfy -= 1;
                }
                if (count[idx2] == 0) {
                    unsatisfy -= 1;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

