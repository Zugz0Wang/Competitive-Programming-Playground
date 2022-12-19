//  @lc app=leetcode id=70 lang=cpp
// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        int array[46];
        array[0] = 1; array[1] = 1; // Base cases
        for(int i = 2; i <= n; i++) {
            array[i] = array[i - 1] + array[i - 2]; // Recursive definition
        }
        return array[n];
    }
};
// @lc code=end