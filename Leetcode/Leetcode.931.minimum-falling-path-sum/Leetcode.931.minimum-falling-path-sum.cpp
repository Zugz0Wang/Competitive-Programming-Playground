/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 *
 * https://leetcode.com/problems/minimum-falling-path-sum/description/
 *
 * algorithms
 * Medium (68.10%)
 * Likes:    3973
 * Dislikes: 114
 * Total Accepted:    205.1K
 * Total Submissions: 296.8K
 * Testcase Example:  '[[2,1,3],[6,5,4],[7,8,9]]'
 *
 * Given an n x n array of integers matrix, return the minimum sum of any
 * falling path through matrix.
 * 
 * A falling path starts at any element in the first row and chooses the
 * element in the next row that is either directly below or diagonally
 * left/right. Specifically, the next element from position (row, col) will be
 * (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
 * Output: 13
 * Explanation: There are two falling paths with a minimum sum as shown.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[-19,57],[-40,-5]]
 * Output: -59
 * Explanation: The falling path with a minimum sum is shown.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == matrix.length == matrix[i].length
 * 1 <= n <= 100
 * -100 <= matrix[i][j] <= 100
 * 
 * 
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int min(int a, int b) {
        if (a < b) {
            return a;
        } else {
            return b;
        }
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        const int kRow = matrix.size();
        const int kCol = matrix.at(0).size();
        if (kRow == 1) {
            return matrix.at(0).at(0);
        }
        int row = 1;
        for (; row < kRow; row++) {
            matrix.at(row).at(0) += min(matrix.at(row - 1).at(0), matrix.at(row - 1).at(1));
            //cout << matrix.at(row).at(0) << ' ';
            for (int col = 1; col < kCol - 1; col++) {

                matrix.at(row).at(col) += min(min(matrix.at(row - 1).at(col - 1), matrix.at(row - 1).at(col)), matrix.at(row - 1).at(col + 1));
                //cout << matrix.at(row).at(col) << ' ';
            }

            matrix.at(row).at(kCol - 1) += min(matrix.at(row - 1).at(kCol - 1), matrix.at(row - 1).at(kCol - 2));
            //cout << matrix.at(row).at(kCol - 1) << ' ';
            //cout << '\n';
        }

        row -= 1;
        int min_val = matrix.at(row).at(0);
        for (int col = 1; col < kCol; col++) {
            int curr_val = matrix.at(row).at(col);
            if (curr_val < min_val) {
                min_val = curr_val;
            }
        }
        return min_val; // [[-69,-87,26,33],[51,81,69,-51],[0,0,0,0],[0,0,0,0]]
        // [[100,-42,-46,-41],[31,97,10,-10],[-58,-51,82,89],[51,81,69,-51]]
        // [[-11,97,10,-10],[-58,-51,82,89],[51,81,69,-51]]
    }
};
// @lc code=end

