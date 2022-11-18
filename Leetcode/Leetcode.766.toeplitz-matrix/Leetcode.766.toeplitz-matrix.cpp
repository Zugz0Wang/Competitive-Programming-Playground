/*
 * @lc app=leetcode id=766 lang=cpp
 *
 * [766] Toeplitz Matrix
 *
 * https://leetcode.com/problems/toeplitz-matrix/description/
 *
 * algorithms
 * Easy (68.09%)
 * Likes:    2201
 * Dislikes: 128
 * Total Accepted:    209.5K
 * Total Submissions: 307.3K
 * Testcase Example:  '[[1,2,3,4],[5,1,2,3],[9,5,1,2]]'
 *
 * Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise,
 * return false.
 * 
 * A matrix is Toeplitz if every diagonal from top-left to bottom-right has the
 * same elements.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
 * Output: true
 * Explanation:
 * In the above grid, the diagonals are:
 * "[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
 * In each diagonal all elements are the same, so the answer is True.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[1,2],[2,2]]
 * Output: false
 * Explanation:
 * The diagonal "[1, 2]" has different elements.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 20
 * 0 <= matrix[i][j] <= 99
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * What if the matrix is stored on disk, and the memory is limited such that
 * you can only load at most one row of the matrix into the memory at once?
 * What if the matrix is so large that you can only load up a partial row into
 * the memory at once?
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        const int kRow = matrix.size();
        const int kCol = matrix.at(0).size();
        for (int i = 0; i < kCol; i++) {
            int row = 0;
            int col = i;
            int value = matrix.at(row).at(col);
            while (row < kRow && col < kCol) {
                if (matrix.at(row).at(col) != value) {
                    return false;
                }
                row++;
                col++;
            }
        }
        for (int i = 0; i < kRow; i++) {
            int row = i;
            int col = 0;
            int value = matrix.at(row).at(col);
            while (row < kRow && col < kCol) {
                if (matrix.at(row).at(col) != value) {
                    return false;
                }
                row++;
                col++;
            }
        }
        for (int i = 0; i < kCol; i++) {
            int row = kRow - 1;
            int col = kCol - 1 - i;
            int value = matrix.at(row).at(col);
            while (row >= 0 && col >= 0) {
                if (matrix.at(row).at(col) != value) {
                    return false;
                }
                row--;
                col--;
            }
        }
        for (int i = 0; i < kRow; i++) {
            int row = kRow - 1 - i;
            int col = kCol - 1;
            int value = matrix.at(row).at(col);
            while (row >= 0 && col >= 0) {
                if (matrix.at(row).at(col) != value) {
                    return false;
                }
                row--;
                col--;
            }
        }
        return true;
    }
};
// @lc code=end

