/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (65.25%)
 * Likes:    12233
 * Dislikes: 377
 * Total Accepted:    1.7M
 * Total Submissions: 2.5M
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings strs, group the anagrams together. You can return
 * the answer in any order.
 * 
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 * 
 * 
 * Example 1:
 * Input: strs = ["eat","tea","tan","ate","nat","bat"]
 * Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
 * Example 2:
 * Input: strs = [""]
 * Output: [[""]]
 * Example 3:
 * Input: strs = ["a"]
 * Output: [["a"]]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= strs.length <= 10^4
 * 0 <= strs[i].length <= 100
 * strs[i] consists of lowercase English letters.
 * 
 * 
 */
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, int> mp;
        vector<vector<string>> to_return;
        int length = 0;
        for (string str : strs) {
            string copy  = str;
            sort(copy.begin(), copy.end());
            if (mp.count(copy) > 0) {
                to_return.at(mp.at(copy)).push_back(str);
            } else {
                mp.insert(pair<string, int>(copy, length));
                length++;
                to_return.push_back({str});
            }
        }
        return to_return;
    }
};
// @lc code=end

