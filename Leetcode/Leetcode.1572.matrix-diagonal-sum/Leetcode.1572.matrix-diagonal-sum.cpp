/*
 * @lc app=leetcode id=1572 lang=cpp
 *
 * [1572] Matrix Diagonal Sum
 *
 * https://leetcode.com/problems/matrix-diagonal-sum/description/
 *
 * algorithms
 * Easy (79.50%)
 * Likes:    2052
 * Dislikes: 27
 * Total Accepted:    181.1K
 * Total Submissions: 225.2K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a square matrix mat, return the sum of the matrix diagonals.
 * 
 * Only include the sum of all the elements on the primary diagonal and all the
 * elements on the secondary diagonal that are not part of the primary
 * diagonal.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: mat = [[1,2,3],
 * [4,5,6],
 * [7,8,9]]
 * Output: 25
 * Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
 * Notice that element mat[1][1] = 5 is counted only once.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: mat = [[1,1,1,1],
 * [1,1,1,1],
 * [1,1,1,1],
 * [1,1,1,1]]
 * Output: 8
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: mat = [[5]]
 * Output: 5
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == mat.length == mat[i].length
 * 1 <= n <= 100
 * 1 <= mat[i][j] <= 100
 * 
 * 
 */
#include <vector>
// @lc code=star
using namespace std;
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) { // Independently solved
        const size_t n(mat.size());
    
        int sum(0);
        for (size_t i(0); i < n; ++i) {
            sum += mat.at(i).at(i);
            sum += mat.at(i).at(n - 1 - i);
        }
        
        if (n % 2 == 1) {
            sum -= mat.at(n / 2).at(n / 2);
        }
        return sum;
    }
};
// @lc code=end

