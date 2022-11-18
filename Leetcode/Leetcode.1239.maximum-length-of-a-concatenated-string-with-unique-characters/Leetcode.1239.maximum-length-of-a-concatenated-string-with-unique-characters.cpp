/*
 * @lc app=leetcode id=1239 lang=cpp
 *
 * [1239] Maximum Length of a Concatenated String with Unique Characters
 *
 * https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/
 *
 * algorithms
 * Medium (50.55%)
 * Likes:    2155
 * Dislikes: 169
 * Total Accepted:    121.1K
 * Total Submissions: 238.3K
 * Testcase Example:  '["un","iq","ue"]'
 *
 * You are given an array of strings arr. A string s is formed by the
 * concatenation of a subsequence of arr that has unique characters.
 * 
 * Return the maximum possible length of s.
 * 
 * A subsequence is an array that can be derived from another array by deleting
 * some or no elements without changing the order of the remaining elements.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = ["un","iq","ue"]
 * Output: 4
 * Explanation: All the valid concatenations are:
 * - ""
 * - "un"
 * - "iq"
 * - "ue"
 * - "uniq" ("un" + "iq")
 * - "ique" ("iq" + "ue")
 * Maximum length is 4.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = ["cha","r","act","ers"]
 * Output: 6
 * Explanation: Possible longest valid concatenations are "chaers" ("cha" +
 * "ers") and "acters" ("act" + "ers").
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
 * Output: 26
 * Explanation: The only string in arr has all 26 characters.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 16
 * 1 <= arr[i].length <= 26
 * arr[i] contains only lowercase English letters.
 * 
 * 
 */
#include <vector>
#include <string>
#include <bitset>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> mp = {bitset<26>()};
        int max_val = 0;
        for (string& str : arr) {
            bitset<26> curr;
            int curr_length = str.length();
            for (char c : str) {
                curr.set(c - 'a');
            }
            if (curr.count() < curr_length) {
                continue;
            }
            for (int i = 0; i < mp.size(); i++) {
                bitset<26>& prev = mp.at(i);
                if ((prev & curr).any()) {
                    continue;
                }
                bitset<26> next = prev | curr;
                int next_len = next.count();
                mp.push_back(next);
                if (next_len > max_val) {
                    max_val = next_len;
                }
            }
        }
        return max_val;
    }
};
// @lc code=end

