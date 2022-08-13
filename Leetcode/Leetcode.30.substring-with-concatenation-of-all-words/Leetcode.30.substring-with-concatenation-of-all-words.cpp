#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        const int kStringLength = s.length();
        const int kNumberOfWords = words.size();
        const int kWordLength = words.at(0).length();
        const int kMatchLength = kNumberOfWords * kWordLength;
        vector<int> to_return;
        unordered_map<string, int> word_count;
        unordered_map<string, int> sub_count;
        for (int i = 0; i < kNumberOfWords; i++) {
            word_count[words.at(i)]  += 1;
        }

        for (int i = 0; i < kStringLength - kMatchLength + 1; i++) {
            sub_count = word_count;
            bool possible = true;
            for (int j = 0; j < kMatchLength; j += kWordLength) {
                string curr_str = s.substr(i + j, kWordLength);
                
                if (sub_count[curr_str] == 0) { // If non-exist word
                    possible = false;
                    break;
                }
                sub_count[curr_str] -= 1;
            }
            
            if (possible) {
                bool empty = true;
                for (int j = 0; j < kNumberOfWords; j++) {
                    if (sub_count[words.at(j)] != 0) { // If all used
                        empty = false;
                        break;
                    }
                }
                if (empty) {
                    to_return.push_back(i);
                }
            }
        }
        return to_return;
    }
};
// @lc code=end

