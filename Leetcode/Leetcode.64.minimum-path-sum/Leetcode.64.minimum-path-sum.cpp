/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (60.15%)
 * Likes:    8260
 * Dislikes: 109
 * Total Accepted:    766.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right, which minimizes the sum of all numbers along its
 * path.
 * 
 * Note: You can only move either down or right at any point in time.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
 * Output: 7
 * Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[1,2,3],[4,5,6]]
 * Output: 12
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 200
 * 0 <= grid[i][j] <= 100
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution { // Original
public:
    int min(int a, int b) {
        return a < b? a : b;
    }
    int minPathSum(vector<vector<int>>& grid) {
        const int kRow = grid.size();
        const int kCol = grid.at(0).size();
        for (int col = kCol - 2; col >= 0; --col) {
            grid.at(kRow - 1).at(col) += grid.at(kRow - 1).at(col + 1);
        }
        for (int row = kRow - 2; row >= 0; --row) {
            grid.at(row).at(kCol - 1) += grid.at(row + 1).at(kCol - 1);
        }

        for (int row = kRow - 2; row >= 0; --row) {
            for (int col = kCol - 2; col >= 0; --col) {
                grid.at(row).at(col) += min(grid.at(row + 1).at(col), grid.at(row).at(col + 1));
            }
        }
        return grid.at(0).at(0);
    }
};
// @lc code=end

