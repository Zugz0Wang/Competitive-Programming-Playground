/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */
#include <string>
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string s) {

        vector<string> patterns(26);
        const int kPatternLength = pattern.length();
        const int kStringLength = s.length();
        int string_idx = 0;
        for (int i = 0; i < kPatternLength; i++) {
            int pattern_idx = pattern.at(i) - 'a';
            string curr_str;
            while (string_idx < kStringLength && s.at(string_idx) != ' ' ) {
                curr_str += s.at(string_idx);
                string_idx++;
                
            }
            if (curr_str.length() == 0) { // If more pattern
                return false;
            }
            string_idx++; // To the next word
            if (patterns.at(pattern_idx).length() == 0) {
                for (string str : patterns) {
                    if (str == curr_str) {
                        return false;
                    }
                }
                patterns.at(pattern_idx) = curr_str;
            } else {
                if (patterns.at(pattern_idx) != curr_str) {
                    return false;
                }
            }
        }
        if (string_idx < kStringLength) { // If more word
            return false;
        } else {
            return true;
        }
    }
};
// @lc code=end

