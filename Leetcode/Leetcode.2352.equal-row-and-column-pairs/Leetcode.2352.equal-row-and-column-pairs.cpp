/*
 * @lc app=leetcode id=2352 lang=cpp
 *
 * [2352] Equal Row and Column Pairs
 *
 * https://leetcode.com/problems/equal-row-and-column-pairs/description/
 *
 * algorithms
 * Medium (71.19%)
 * Likes:    1173
 * Dislikes: 64
 * Total Accepted:    75.9K
 * Total Submissions: 102.4K
 * Testcase Example:  '[[3,2,1],[1,7,6],[2,7,7]]'
 *
 * Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri,
 * cj) such that row ri and column cj are equal.
 * 
 * A row and column pair is considered equal if they contain the same elements
 * in the same order (i.e., an equal array).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
 * Output: 1
 * Explanation: There is 1 equal row and column pair:
 * - (Row 2, Column 1): [2,7,7]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
 * Output: 3
 * Explanation: There are 3 equal row and column pairs:
 * - (Row 0, Column 0): [3,1,2,2]
 * - (Row 2, Column 2): [2,4,2,2]
 * - (Row 3, Column 2): [2,4,2,2]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == grid.length == grid[i].length
 * 1 <= n <= 200
 * 1 <= grid[i][j] <= 10^5
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int count(0);
        const size_t N(grid.size());
        for (size_t i(0); i < N; ++i) {
            for (size_t j(0); j < N; ++j) {
                bool same(true);
                for (size_t k(0); k < N; ++k) {
                    if (grid.at(i).at(k) != grid.at(k).at(j)) {
                        same = false;
                        break;
                    }
                }
                if (same) {
                    count += 1;
                }
            }
        }
        
        return count;
    }
};
// @lc code=end

