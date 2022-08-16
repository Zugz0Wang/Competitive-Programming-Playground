/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> nums(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            nums.at(i) = nums.at(i >> 1) + (i & 1); // Same as i / 2 and i % 2
        }
        return nums;
    }
};
// @lc code=end

