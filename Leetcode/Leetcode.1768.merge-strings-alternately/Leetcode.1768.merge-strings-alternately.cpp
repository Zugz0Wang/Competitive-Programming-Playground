/*
 * @lc app=leetcode id=1768 lang=cpp
 *
 * [1768] Merge Strings Alternately
 *
 * https://leetcode.com/problems/merge-strings-alternately/description/
 *
 * algorithms
 * Easy (75.89%)
 * Likes:    1038
 * Dislikes: 18
 * Total Accepted:    103.1K
 * Total Submissions: 131.9K
 * Testcase Example:  '"abc"\n"pqr"'
 *
 * You are given two strings word1 and word2. Merge the strings by adding
 * letters in alternating order, starting with word1. If a string is longer
 * than the other, append the additional letters onto the end of the merged
 * string.
 * 
 * Return the merged string.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: word1 = "abc", word2 = "pqr"
 * Output: "apbqcr"
 * Explanation: The merged string will be merged as so:
 * word1:  a   b   c
 * word2:    p   q   r
 * merged: a p b q c r
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: word1 = "ab", word2 = "pqrs"
 * Output: "apbqrs"
 * Explanation: Notice that as word2 is longer, "rs" is appended to the end.
 * word1:  a   b 
 * word2:    p   q   r   s
 * merged: a p b q   r   s
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: word1 = "abcd", word2 = "pq"
 * Output: "apbqcd"
 * Explanation: Notice that as word1 is longer, "cd" is appended to the end.
 * word1:  a   b   c   d
 * word2:    p   q 
 * merged: a p b q c   d
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= word1.length, word2.length <= 100
 * word1 and word2 consist of lowercase English letters.
 * 
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    string mergeAlternately(string word1, string word2) { // Independently solved
        const int size1(word1.size());
        const int size2(word2.size());
        const int size(size1 + size2);
        string ans(size, 'a');
        const int m_size(min(size1, size2));
        for (int i(0); i < m_size; ++i) {
            const int i2(i * 2);
            ans.at(i2) = word1.at(i);
            ans.at(i2 + 1) = word2.at(i);
        }
        const int offset(m_size);
        if (size1 > size2) {
            for (int i(m_size); i < size1; ++i) {
                ans.at(offset + i) = word1.at(i);
            }
        } else {
            for (int i(m_size); i < size2; ++i) {
                ans.at(offset + i) = word2.at(i);
            }
        }
        return ans;
    }
};
// @lc code=end

