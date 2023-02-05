/*
 * @lc app=leetcode id=953 lang=cpp
 *
 * [953] Verifying an Alien Dictionary
 *
 * https://leetcode.com/problems/verifying-an-alien-dictionary/description/
 *
 * algorithms
 * Easy (52.59%)
 * Likes:    3314
 * Dislikes: 1077
 * Total Accepted:    385.3K
 * Total Submissions: 728.7K
 * Testcase Example:  '["hello","leetcode"]\n"hlabcdefgijkmnopqrstuvwxyz"'
 *
 * In an alien language, surprisingly, they also use English lowercase letters,
 * but possibly in a different order. The order of the alphabet is some
 * permutation of lowercase letters.
 * 
 * Given a sequence of words written in the alien language, and the order of
 * the alphabet, return true if and only if the given words are sorted
 * lexicographically in this alien language.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
 * Output: true
 * Explanation: As 'h' comes before 'l' in this language, then the sequence is
 * sorted.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
 * Output: false
 * Explanation: As 'd' comes after 'l' in this language, then words[0] >
 * words[1], hence the sequence is unsorted.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
 * Output: false
 * Explanation: The first three characters "app" match, and the second string
 * is shorter (in size.) According to lexicographical rules "apple" > "app",
 * because 'l' > '∅', where '∅' is defined as the blank character which is less
 * than any other character (More info).
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= words.length <= 100
 * 1 <= words[i].length <= 20
 * order.length == 26
 * All characters in words[i] and order are English lowercase letters.
 * 
 * 
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    unsigned int mp[26];
    bool valid(string& a, string& b) {
        const int size_a = a.size();
        const int size_b = b.size();
        int size = 0;
        bool shorter = size_a <= size_b;
        if (shorter) {
            size = size_a;
        } else {
            size = size_b;
        }
        for (int i = 0; i < size; i++) {
            int a_rank = mp[a.at(i) - 'a'];
            int b_rank = mp[b.at(i) - 'a'];
            if (a_rank > b_rank) {
                return false;
            } else if (a_rank < b_rank) {
                return true;
            }
        }
        return shorter;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        for (int i = 0; i < 26; i++) {
            mp[order.at(i) - 'a'] = i;
        }
        for (int i = 1; i < words.size(); i++) {
            if (!valid(words.at(i - 1), words.at(i))) {
                return false;
            }
        }
        return true;
    }
};
// ["hello", "hell"]\n"hlabcdefgijkmnopqrstuvwxyz"
// @lc code=end

