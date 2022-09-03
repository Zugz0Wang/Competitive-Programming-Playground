/*
 * @lc app=leetcode id=1329 lang=cpp
 *
 * [1329] Sort the Matrix Diagonally
 *
 * https://leetcode.com/problems/sort-the-matrix-diagonally/description/
 *
 * algorithms
 * Medium (81.42%)
 * Likes:    2557
 * Dislikes: 199
 * Total Accepted:    121.6K
 * Total Submissions: 145.9K
 * Testcase Example:  '[[3,3,1,1],[2,2,1,2],[1,1,1,2]]'
 *
 * A matrix diagonal is a diagonal line of cells starting from some cell in
 * either the topmost row or leftmost column and going in the bottom-right
 * direction until reaching the matrix's end. For example, the matrix diagonal
 * starting from mat[2][0], where mat is a 6 x 3 matrix, includes cells
 * mat[2][0], mat[3][1], and mat[4][2].
 * 
 * Given an m x n matrix mat of integers, sort each matrix diagonal in
 * ascending order and return the resulting matrix.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
 * Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: mat =
 * [[11,25,66,1,69,7],[23,55,17,45,15,52],[75,31,36,44,58,8],[22,27,33,25,68,4],[84,28,14,11,5,50]]
 * Output:
 * [[5,17,4,1,52,7],[11,11,25,45,8,69],[14,23,25,44,58,15],[22,27,31,36,50,66],[84,28,75,33,55,68]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 100
 * 1 <= mat[i][j] <= 100
 * 
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        const int kRow = mat.size();
        const int kCol = mat.at(0).size();
        vector<vector<int>> to_return = mat;
        for (int col = 0; col < kCol; col++) {
            int i = 0;
            int j = col;
            vector<int> dia;
            while (i < kRow && j < kCol) {
                dia.push_back(mat.at(i).at(j));
                i++;
                j++;
            }
            sort(dia.begin(), dia.end());
            i = 0;
            j = col;
            int count = 0;
            while (i < kRow && j < kCol) {
                to_return.at(i).at(j) = dia.at(count);
                i++;
                j++;
                count++;
            }
        }
        for (int row = 1; row < kRow; row++) {
            int i = row;
            int j = 0;
            vector<int> dia;
            while (i < kRow && j < kCol) {
                dia.push_back(mat.at(i).at(j));
                i++;
                j++;
            }
            sort(dia.begin(), dia.end());
            i = row;
            j = 0;
            int count = 0;
            while (i < kRow && j < kCol) {
                to_return.at(i).at(j) = dia.at(count);
                i++;
                j++;
                count++;
            }
        }
        return to_return;
    }
};
// @lc code=end

