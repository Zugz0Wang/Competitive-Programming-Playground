/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 *
 * https://leetcode.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (46.00%)
 * Likes:    9494
 * Dislikes: 302
 * Total Accepted:    962.7K
 * Total Submissions: 2.1M
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n3'
 *
 * Write an efficient algorithm that searches for a value target in an m x n
 * integer matrix matrix. This matrix has the following properties:
 * 
 * 
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the
 * previous row.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 100
 * -10^4 <= matrix[i][j], target <= 10^4
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int kCol = matrix.at(0).size();
        const int kSize = matrix.size() * kCol;
        
        int head = 0;
        int tail = kSize;
        while (head < tail) {
            int mid = (head + tail) / 2;
            int row = mid / kCol;
            int col = mid % kCol;
            int curr = matrix.at(row).at(col);
            if (curr == target) {
                return true;
            } else if (curr > target) {
                tail = mid;
            } else {
                head = mid + 1;
            }
        }
        return false;
    }
};
// @lc code=end

