/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 *
 * https://leetcode.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (65.90%)
 * Likes:    4892
 * Dislikes: 211
 * Total Accepted:    437.8K
 * Total Submissions: 647.6K
 * Testcase Example:  '3'
 *
 * Given a positive integer n, generate an n x n matrix filled with elements
 * from 1 to n^2 in spiral order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3
 * Output: [[1,2,3],[8,9,4],[7,6,5]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1
 * Output: [[1]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 20
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) { // Independently solved
        size_t row0(0);
        size_t col0(0);
        size_t row1(n);
        size_t col1(n);
        
        size_t head(1);
        size_t total(row1 * col1);
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        while (head <= total) {

            bool single_row(row0 == row1 - 1);
            bool single_col(col0 == col1 - 1);
            
            if (single_row && single_col) {
                matrix.at(row0).at(col0) = head;
                ++head;
                break;
            } else if (single_row) {
                for (size_t col(col0); col < col1; ++col) {
                    matrix.at(row0).at(col) = head;
                    ++head;
                }
                break;
            } else if (single_col) {
                 for (size_t row(row0); row < row1; ++row) {
                    matrix.at(row).at(col0) = head;
                    ++head;
                }
                break;
            }

            for (size_t col(col0); col < col1 - 1; ++col) {
                 matrix.at(row0).at(col) = head;
                ++head;
            }

            for (size_t row(row0); row < row1 - 1; ++row) {
                matrix.at(row).at(col1 - 1) = head;
                ++head;
            }
            
            for (size_t col(col1 - 1); col > col0; --col) {
                matrix.at(row1 - 1).at(col) = head;
                ++head;
            }

            for (size_t row(row1 - 1); row > row0; --row) {
                matrix.at(row).at(col0) = head;
                ++head;
            }
            
            ++row0;
            ++col0;
            --row1;
            --col1;
        }
        return matrix;
    }
};
// @lc code=end

