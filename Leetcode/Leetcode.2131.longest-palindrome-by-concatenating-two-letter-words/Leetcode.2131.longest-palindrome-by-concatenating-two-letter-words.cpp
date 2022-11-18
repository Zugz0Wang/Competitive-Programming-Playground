/*
 * @lc app=leetcode id=2131 lang=cpp
 *
 * [2131] Longest Palindrome by Concatenating Two Letter Words
 *
 * https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/description/
 *
 * algorithms
 * Medium (40.75%)
 * Likes:    745
 * Dislikes: 20
 * Total Accepted:    33.5K
 * Total Submissions: 80.7K
 * Testcase Example:  '["lc","cl","gg"]'
 *
 * You are given an array of strings words. Each element of words consists of
 * two lowercase English letters.
 * 
 * Create the longest possible palindrome by selecting some elements from words
 * and concatenating them in any order. Each element can be selected at most
 * once.
 * 
 * Return the length of the longest palindrome that you can create. If it is
 * impossible to create any palindrome, return 0.
 * 
 * A palindrome is a string that reads the same forward and backward.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: words = ["lc","cl","gg"]
 * Output: 6
 * Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of
 * length 6.
 * Note that "clgglc" is another longest palindrome that can be created.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: words = ["ab","ty","yt","lc","cl","ab"]
 * Output: 8
 * Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" =
 * "tylcclyt", of length 8.
 * Note that "lcyttycl" is another longest palindrome that can be created.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: words = ["cc","ll","xx"]
 * Output: 2
 * Explanation: One longest palindrome is "cc", of length 2.
 * Note that "ll" is another longest palindrome that can be created, and so is
 * "xx".
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= words.length <= 10^5
 * words[i].length == 2
 * words[i] consists of lowercase English letters.
 * 
 * 
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    int count[700];
    int index(string& word) {
        return (word.at(0) - 'a') * 26 + (word.at(1) - 'a');
    }
    int reverse(string& word) {
        return (word.at(1) - 'a') * 26 + (word.at(0) - 'a');
    }
    int longestPalindrome(vector<string>& words) {
        memset(count, 0, sizeof(count));
        int length = 0;
        for (string& word : words) {
            int idx = index(word);
            int idx_r = reverse(word);
            if (count[idx_r] > 0) {
                count[idx_r]--;
                length += 4;
            } else {
                count[idx]++;
            }
        }
        for (string& word : words) {
            int idx = index(word);
            if (word.at(0) == word.at(1) && count[idx] > 0) {
                length += 2;
                break;
            }
        }
        return length;
    }
};
// @lc code=end

