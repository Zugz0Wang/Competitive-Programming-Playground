/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (54.99%)
 * Likes:    16110
 * Dislikes: 873
 * Total Accepted:    1.6M
 * Total Submissions: 2.8M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent. Return the answer in
 * any order.
 * 
 * A mapping of digits to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: digits = "23"
 * Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: digits = ""
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: digits = "2"
 * Output: ["a","b","c"]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= digits.length <= 4
 * digits[i] is a digit in the range ['2', '9'].
 * 
 * 
 */

// @lc code=start
class Solution { // Independently solved
public:
    vector<string> dict {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string digits;
    string path;
    vector<string> ans;
    void helper(size_t i) {
        
        string& curr(dict.at(digits.at(i) - '2'));
        for (char c : curr) {
            path.push_back(c);
            if (i + 1 >= digits.size()) {
                ans.push_back(path);
            } else {
                helper(i + 1);
            }
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits_) {
        digits = digits_;
        if (digits.size() > 0) {
            helper(0);
        }
        return ans;
    }
};
// @lc code=end

