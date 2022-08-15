/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */
#include <string>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        string to_return;
        int rows[1000];
        const int kLength = s.length();
        if (numRows == 1 || numRows == kLength) {
            to_return = s;
            return to_return;
        }
        int i = 0;
        bool zig = true;
        int row = 0;
        while (i < kLength) { // Simulation
            if (zig) {
                if (row < numRows) {
                    rows[i] = row;
                    i++;
                    row++;
                } else {
                    row -= 2;
                    zig = false;
                }
            } else {
                if (row > 0) {
                    rows[i] = row;
                    row--;
                    i++;
                } else {
                    zig = true;
                }
            }

        }
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < kLength; j++) {
                if (rows[j] == i) {
                    to_return += s[j];
                }
            }
        }
        return to_return;
    }
};
// @lc code=end

