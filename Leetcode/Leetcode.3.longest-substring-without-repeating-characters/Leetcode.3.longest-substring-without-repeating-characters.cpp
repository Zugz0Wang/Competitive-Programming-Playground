/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
#include <string>
#include <set>
using namespace std;
// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int head = 0;
        int tail = 0;
        int curr_length = 0;
        int max = 0;
        set<char> substring;
        const int kLength = s.length();
        while (head < kLength) {
            char curr_char = s[head];
            if (substring.count(curr_char) == 0) { // If new char
                head++;
                substring.insert(curr_char);
                curr_length++;
                if (curr_length > max) {
                    max = curr_length;
                }
            } else { // If duplicate char
                char tail_char = s[tail];
                substring.erase(tail_char);
                tail++;
                curr_length--;
            }
        }
        return max;
    }
};
// @lc code=end

