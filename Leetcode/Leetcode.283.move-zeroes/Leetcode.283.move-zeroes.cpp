/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        bool zero_available = false;
        int prev_zero_idx = 0;
        const int kSize = nums.size();
        int i = 0;
        while (i < kSize) {
            int curr_num = nums.at(i);
            if (curr_num != 0) {
                if (zero_available) {
                    nums.at(prev_zero_idx) = curr_num;
                    nums.at(i) = 0;
                    prev_zero_idx += 1;
                    while (prev_zero_idx < i + 1 && nums.at(prev_zero_idx) != 0) {
                        prev_zero_idx++; // Find next zero
                    }
                }
            } else {
                if (!zero_available) { // The first zero
                    zero_available = true;
                    prev_zero_idx = i;
                }
            }
            i++;
        }
    }
};
// @lc code=end

