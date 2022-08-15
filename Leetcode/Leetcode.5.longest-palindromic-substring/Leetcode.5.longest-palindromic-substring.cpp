/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */
#include <string>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int max_length = 0;
        string max_string;
        const int kLength = s.length();
        for (int i = 0; i < kLength; i++) { // Check every position as a center of a odd palindrome
            int length = 1;
            int head = i;
            int tail = i + 1;
            while (head >= 0 && tail <= kLength) {
                if (s[head] == s[tail - 1]) {
                    length += 2;
                    head--;
                    tail++;
                } else {
                    break;
                }
            }
            if (length > max_length) {
                max_length = length;
                max_string = s.substr(head + 1, length - 2);
            }
        }
        for (int i = 0; i < kLength - 1; i++) { // Check every position as a center of a even palindrome
            if (s[i] != s[i + 1]) {
                continue;
            }
            int length = 2;
            int head = i;
            int tail = i + 2;
            while (head >= 0 && tail <= kLength) {
                if (s[head] == s[tail - 1]) {
                    length += 2;
                    head--;
                    tail++;
                } else {
                    break;
                }
            }
            if (length > max_length) {
                max_length = length;
                max_string = s.substr(head + 1, length - 2);
            }
        }
        return max_string;
    }
};
// @lc code=end

