/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const unsigned int n = nums.size();
        unsigned int total = ((n + 1) * n) / 2;
        for (int i : nums) {
            total -= i;
        }
        return total;
    }
};
// @lc code=end

