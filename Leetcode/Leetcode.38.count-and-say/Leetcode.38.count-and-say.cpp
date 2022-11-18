/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Medium (49.36%)
 * Likes:    2201
 * Dislikes: 4872
 * Total Accepted:    691.5K
 * Total Submissions: 1.4M
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is a sequence of digit strings defined by the
 * recursive formula:
 * 
 * 
 * countAndSay(1) = "1"
 * countAndSay(n) is the way you would "say" the digit string from
 * countAndSay(n-1), which is then converted into a different digit string.
 * 
 * 
 * To determine how you "say" a digit string, split it into the minimal number
 * of substrings such that each substring contains exactly one unique digit.
 * Then for each substring, say the number of digits, then say the digit.
 * Finally, concatenate every said digit.
 * 
 * For example, the saying and conversion for digit string "3322251":
 * 
 * Given a positive integer n, return the n^th term of the count-and-say
 * sequence.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 1
 * Output: "1"
 * Explanation: This is the base case.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 4
 * Output: "1211"
 * Explanation:
 * countAndSay(1) = "1"
 * countAndSay(2) = say "1" = one 1 = "11"
 * countAndSay(3) = say "11" = two 1's = "21"
 * countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 30
 * 
 * 
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        string to_return = "1";

        for (int i = 1; i < n; i++) {
            string next_str = "";
            int head = 0;
            const int kLength = to_return.length();
            
            while (head < kLength) {
                int count = 0;
                int next = head;
                char curr_char = to_return.at(head);
                while (next < kLength && to_return.at(next) == curr_char) {
                    next++;
                    count++;
                }
                next_str += to_string(count) + curr_char;
                head = next;
            }
            to_return = next_str;
        }

        return to_return;
    }
};
// @lc code=end

