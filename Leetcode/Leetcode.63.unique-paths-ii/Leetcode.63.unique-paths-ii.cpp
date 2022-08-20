/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 *
 * https://leetcode.com/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (38.83%)
 * Likes:    5767
 * Dislikes: 405
 * Total Accepted:    588.5K
 * Total Submissions: 1.5M
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * You are given an m x n integer array grid. There is a robot initially
 * located at the top-left corner (i.e., grid[0][0]). The robot tries to move
 * to the bottom-right corner (i.e., grid[m-1][n-1]). The robot can only move
 * either down or right at any point in time.
 * 
 * An obstacle and space are marked as 1 or 0 respectively in grid. A path that
 * the robot takes cannot include any square that is an obstacle.
 * 
 * Return the number of possible unique paths that the robot can take to reach
 * the bottom-right corner.
 * 
 * The testcases are generated so that the answer will be less than or equal to
 * 2 * 10^9.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
 * Output: 2
 * Explanation: There is one obstacle in the middle of the 3x3 grid above.
 * There are two ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down -> Down
 * 2. Down -> Down -> Right -> Right
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: obstacleGrid = [[0,1],[0,0]]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == obstacleGrid.length
 * n == obstacleGrid[i].length
 * 1 <= m, n <= 100
 * obstacleGrid[i][j] is 0 or 1.
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> dp_table;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const int kM = obstacleGrid.size();
        const int kN = obstacleGrid.at(0).size();
        vector<int> row(kN, 0);
        dp_table.assign(kM, row);
        if (obstacleGrid.at(0).at(0) == 1) {
            return 0;
        }
        dp_table.at(0).at(0) = 1;
        for (int i = 0; i < kM; i++) {
            for (int j = 0; j < kN; j++) {
                int prev0 = i - 1;
                int prev1 = j - 1;
                if (obstacleGrid.at(i).at(j) == 1) {
                    continue;
                }
                if (prev0 >= 0) {
                    dp_table.at(i).at(j) += dp_table.at(prev0).at(j);
                }
                if (prev1 >= 0) {
                    dp_table.at(i).at(j) += dp_table.at(i).at(prev1);
                }
            }
        }
        return dp_table.at(kM - 1).at(kN - 1);
    }
};
// @lc code=end

