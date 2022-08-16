/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> count;
        for (char i : s) {
            if (count.count(i) == 0) {
                count.insert(pair<char, int>(i, 1));
            } else {
                count.at(i) += 1;
            }
        }
        for (char i : t) {
            if (count.count(i) == 0) {
                return false;
            } else {
                count.at(i) -= 1;
            }
        }
        for (char i : s) {
            if (count.at(i) != 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

