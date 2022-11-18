/*
 * @lc app=leetcode id=1662 lang=cpp
 *
 * [1662] Check If Two String Arrays are Equivalent
 *
 * https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/description/
 *
 * algorithms
 * Easy (81.84%)
 * Likes:    1074
 * Dislikes: 123
 * Total Accepted:    171K
 * Total Submissions: 208.9K
 * Testcase Example:  '["ab", "c"]\n["a", "bc"]'
 *
 * Given two string arrays word1 and word2, return true if the two arrays
 * represent the same string, and false otherwise.
 * 
 * A string is represented by an array if the array elements concatenated in
 * order forms the string.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
 * Output: true
 * Explanation:
 * word1 represents string "ab" + "c" -> "abc"
 * word2 represents string "a" + "bc" -> "abc"
 * The strings are the same, so return true.
 * 
 * Example 2:
 * 
 * 
 * Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
 * Output: true
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= word1.length, word2.length <= 10^3
 * 1 <= word1[i].length, word2[i].length <= 10^3
 * 1 <= sum(word1[i].length), sum(word2[i].length) <= 10^3
 * word1[i] and word2[i] consist of lowercase letters.
 * 
 * 
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        const int kSize1 = word1.size();
        const int kSize2 = word2.size();
        if (kSize1 == 0 && kSize2 == 0) {
            return true;
        }
        int word_idx1 = 0;
        int word_idx2 = 0;
        int char_idx1 = 0;
        int char_idx2 = 0;
        do {
            while (word_idx1 < kSize1 && char_idx1 >= word1.at(word_idx1).length()) {
                char_idx1 = 0;
                word_idx1 += 1;
            }
            while (word_idx2 < kSize2 && char_idx2 >= word2.at(word_idx2).length()) {
                char_idx2 = 0;
                word_idx2 += 1;
            }
            if ((word_idx1 >= kSize1) == (word_idx2 >= kSize2)) {
                if (word_idx1 >= kSize1) {
                    break;
                }
            } else {
                return false;
            }
            if (word1.at(word_idx1).at(char_idx1) != word2.at(word_idx2).at(char_idx2)) {
                return false;
            }
            char_idx1 += 1;
            char_idx2 += 1;
        } while (true);

        return true;
    }
};
// @lc code=end

