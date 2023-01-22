/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 *
 * https://leetcode.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (42.78%)
 * Likes:    2999
 * Dislikes: 637
 * Total Accepted:    315.8K
 * Total Submissions: 737.3K
 * Testcase Example:  '"25525511135"'
 *
 * A valid IP address consists of exactly four integers separated by single
 * dots. Each integer is between 0 and 255 (inclusive) and cannot have leading
 * zeros.
 * 
 * 
 * For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but
 * "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP
 * addresses.
 * 
 * 
 * Given a string s containing only digits, return all possible valid IP
 * addresses that can be formed by inserting dots into s. You are not allowed
 * to reorder or remove any digits in s. You may return the valid IP addresses
 * in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "25525511135"
 * Output: ["255.255.11.135","255.255.111.35"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "0000"
 * Output: ["0.0.0.0"]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "101023"
 * Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 20
 * s consists of digits only.
 * 
 * 
 */

// @lc code=start
class Solution {
    // Adapted from the leetcode solution
    bool valid(const string& s, int start, int length) {
        return length == 1 || (s[start] != '0' && (length < 3)) || (length == 3 && (
            (s.at(start) == '2' && s.at(start + 1) <= '4') ||
            (s.at(start) == '2' && s.at(start + 1) == '5' && s.at(start + 2) <= '5') ||
            (s.at(start) == '1' && s.at(start + 1) <= '9' && s.at(start + 2) <= '9')));
    }

    void helper(const string& s, int startIndex) {
        const int remainingLength = s.length() - startIndex;
        const int remainingNumberOfIntegers = 4 - dots.size();

        if (remainingLength > remainingNumberOfIntegers * 3 ||
            remainingLength < remainingNumberOfIntegers) {
            return;
        }
        if (dots.size() == 3) {
            if (valid(s, startIndex, remainingLength)) {
                string temp;
                int last = 0;
                for (int dot : dots) {
                    temp += s.substr(last, dot);
                    last += dot;
                    temp += '.';
                }
                temp.append(s.substr(startIndex));
                ans.push_back(temp);
            }
            return;
        }
        for (int curPos = 1; curPos <= 3 && curPos <= remainingLength; ++curPos) {
            // Append a dot at the current position.
            dots.push_back(curPos);
            // Try making all combinations with the remaining string.
            if (valid(s, startIndex, curPos)) {
                helper(s, startIndex + curPos);
            }
            // Backtrack, i.e. remove the dot to try placing it at the next position.
            dots.pop_back();
        }
    }

public:
    vector<int> dots;
    vector<string> ans;
    vector<string> restoreIpAddresses(string s) {
        helper(s, 0);
        return ans;
    }
};
// @lc code=end

