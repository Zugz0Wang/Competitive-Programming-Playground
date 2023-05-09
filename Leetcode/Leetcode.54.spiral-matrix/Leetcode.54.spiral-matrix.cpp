/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (42.75%)
 * Likes:    11234
 * Dislikes: 1040
 * Total Accepted:    1M
 * Total Submissions: 2.3M
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given an m x n matrix, return all elements of the matrix in spiral order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 10
 * -100 <= matrix[i][j] <= 100
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) { // Independently solved
        size_t row0(0);
        size_t col0(0);
        size_t row1(matrix.size());
        size_t col1(matrix.at(0).size());
        
        size_t head(0);
        size_t total(row1 * col1);
        vector<int> ans(total, 0);
        while (head < total) {

            bool single_row(row0 == row1 - 1);
            bool single_col(col0 == col1 - 1);
            
            if (single_row && single_col) {
                ans.at(head) = matrix.at(row0).at(col0);
                ++head;
                break;
            } else if (single_row) {
                for (size_t col(col0); col < col1; ++col) {
                    ans.at(head) = matrix.at(row0).at(col);
                    ++head;
                }
                break;
            } else if (single_col) {
                 for (size_t row(row0); row < row1; ++row) {
                    ans.at(head) = matrix.at(row).at(col0);
                    ++head;
                }
                break;
            }

            for (size_t col(col0); col < col1 - 1; ++col) {
                ans.at(head) = matrix.at(row0).at(col);
                ++head;
            }

            for (size_t row(row0); row < row1 - 1; ++row) {
                ans.at(head) = matrix.at(row).at(col1 - 1);
                ++head;
            }
            
            for (size_t col(col1 - 1); col > col0; --col) {
                ans.at(head) = matrix.at(row1 - 1).at(col);
                ++head;
            }

            for (size_t row(row1 - 1); row > row0; --row) {
                ans.at(head) = matrix.at(row).at(col0);
                ++head;
            }
            
            ++row0;
            ++col0;
            --row1;
            --col1;
        }
        return ans;
    }
};
// @lc code=end

