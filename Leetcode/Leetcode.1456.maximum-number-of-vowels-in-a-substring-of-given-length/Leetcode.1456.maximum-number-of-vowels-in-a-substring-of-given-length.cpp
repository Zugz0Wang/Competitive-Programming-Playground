/*
 * @lc app=leetcode id=1456 lang=cpp
 *
 * [1456] Maximum Number of Vowels in a Substring of Given Length
 *
 * https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/
 *
 * algorithms
 * Medium (57.72%)
 * Likes:    1145
 * Dislikes: 51
 * Total Accepted:    60.5K
 * Total Submissions: 103.7K
 * Testcase Example:  '"abciiidef"\n3'
 *
 * Given a string s and an integer k, return the maximum number of vowel
 * letters in any substring of s with length k.
 * 
 * Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abciiidef", k = 3
 * Output: 3
 * Explanation: The substring "iii" contains 3 vowel letters.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "aeiou", k = 2
 * Output: 2
 * Explanation: Any substring of length 2 contains 2 vowels.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "leetcode", k = 3
 * Output: 2
 * Explanation: "lee", "eet" and "ode" contain 2 vowels.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s consists of lowercase English letters.
 * 1 <= k <= s.length
 * 
 * 
 */
#include <string>
using namespace std;
// @lc code=start
class Solution { // Independently solved
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ;
    }
    int maxVowels(string s, int k) {
        int window_count(0);
        for (int i(0); i < k; ++i) {
            if (isVowel(s.at(i))) {
                ++window_count;
            }
        }
        int max_count(window_count);
        const int s_size(s.size());
        for (int i(k); i < s_size; ++i) {
            
            int prev_idx(i - k);
            int add(isVowel(s.at(i)));
            int sub(isVowel(s.at(prev_idx)));
            // cout << window_count << ' ';
            window_count = window_count + add - sub;
            if (window_count > max_count) {
                max_count = window_count;
            }
        }
        return max_count;
    }
};
// @lc code=end

