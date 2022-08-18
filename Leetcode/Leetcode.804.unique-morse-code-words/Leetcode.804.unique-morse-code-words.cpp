/*
 * @lc app=leetcode id=804 lang=cpp
 *
 * [804] Unique Morse Code Words
 *
 * https://leetcode.com/problems/unique-morse-code-words/description/
 *
 * algorithms
 * Easy (80.24%)
 * Likes:    1865
 * Dislikes: 1309
 * Total Accepted:    273K
 * Total Submissions: 332.4K
 * Testcase Example:  '["gin","zen","gig","msg"]'
 *
 * International Morse Code defines a standard encoding where each letter is
 * mapped to a series of dots and dashes, as follows:
 * 
 * 
 * 'a' maps to ".-",
 * 'b' maps to "-...",
 * 'c' maps to "-.-.", and so on.
 * 
 * 
 * For convenience, the full table for the 26 letters of the English alphabet
 * is given below:
 * 
 * 
 * 
 * [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
 * 
 * Given an array of strings words where each word can be written as a
 * concatenation of the Morse code of each letter.
 * 
 * 
 * For example, "cab" can be written as "-.-..--...", which is the
 * concatenation of "-.-.", ".-", and "-...". We will call such a concatenation
 * the transformation of a word.
 * 
 * 
 * Return the number of different transformations among all words we have.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: words = ["gin","zen","gig","msg"]
 * Output: 2
 * Explanation: The transformation of each word is:
 * "gin" -> "--...-."
 * "zen" -> "--...-."
 * "gig" -> "--...--."
 * "msg" -> "--...--."
 * There are 2 different transformations: "--...-." and "--...--.".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: words = ["a"]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= words.length <= 100
 * 1 <= words[i].length <= 12
 * words[i] consists of lowercase English letters.
 * 
 * 
 */
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse_table = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> existed;
        int count = 0;
        for (string word : words) {
            string morse;
            for (char c : word) {
                morse += morse_table.at(c - 'a');
            }
            if (existed.count(morse) == 0) {
                count++;
                existed.insert(morse);
            } 
        }
        return count;
    }
};
// @lc code=end

