/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 *
 * https://leetcode.com/problems/pacific-atlantic-water-flow/description/
 *
 * algorithms
 * Medium (51.10%)
 * Likes:    5426
 * Dislikes: 1030
 * Total Accepted:    284.8K
 * Total Submissions: 534.2K
 * Testcase Example:  '[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]'
 *
 * There is an m x n rectangular island that borders both the Pacific Ocean and
 * Atlantic Ocean. The Pacific Ocean touches the island's left and top edges,
 * and the Atlantic Ocean touches the island's right and bottom edges.
 * 
 * The island is partitioned into a grid of square cells. You are given an m x
 * n integer matrix heights where heights[r][c] represents the height above sea
 * level of the cell at coordinate (r, c).
 * 
 * The island receives a lot of rain, and the rain water can flow to
 * neighboring cells directly north, south, east, and west if the neighboring
 * cell's height is less than or equal to the current cell's height. Water can
 * flow from any cell adjacent to an ocean into the ocean.
 * 
 * Return a 2D list of grid coordinates result where result[i] = [ri, ci]
 * denotes that rain water can flow from cell (ri, ci) to both the Pacific and
 * Atlantic oceans.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: heights =
 * [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
 * Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
 * Explanation: The following cells can flow to the Pacific and Atlantic
 * oceans, as shown below:
 * [0,4]: [0,4] -> Pacific Ocean 
 * [0,4] -> Atlantic Ocean
 * [1,3]: [1,3] -> [0,3] -> Pacific Ocean 
 * [1,3] -> [1,4] -> Atlantic Ocean
 * [1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean 
 * [1,4] -> Atlantic Ocean
 * [2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean 
 * [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
 * [3,0]: [3,0] -> Pacific Ocean 
 * [3,0] -> [4,0] -> Atlantic Ocean
 * [3,1]: [3,1] -> [3,0] -> Pacific Ocean 
 * [3,1] -> [4,1] -> Atlantic Ocean
 * [4,0]: [4,0] -> Pacific Ocean 
 * ⁠      [4,0] -> Atlantic Ocean
 * Note that there are other possible paths for these cells to flow to the
 * Pacific and Atlantic oceans.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: heights = [[1]]
 * Output: [[0,0]]
 * Explanation: The water can flow from the only cell to the Pacific and
 * Atlantic oceans.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == heights.length
 * n == heights[r].length
 * 1 <= m, n <= 200
 * 0 <= heights[r][c] <= 10^5
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool atl[200][200];
    bool pac[200][200];
    bool on[200][200];
    vector<vector<int>> heights_;
    int kRow;
    int kCol;
    bool reachable(int row, int col) {
        return (row >= 0 && row < kRow) && (col >= 0 && col < kCol);
    }
    bool isAtl(int row, int col) {
        if (!reachable(row, col) || on[row][col]) {
            return false;
        }
        if (atl[row][col]) {
            return true;
        }
        int height = heights_.at(row).at(col);

        on[row][col] = true;
        bool ans = false;
        if (!ans && row > 0 && heights_.at(row - 1).at(col) <= height) {
            ans = isAtl(row - 1, col);
        }
        if (!ans && col > 0 && heights_.at(row).at(col - 1) <= height) {
            ans = isAtl(row, col - 1);
        }
        if (!ans && row < kRow - 1 && heights_.at(row + 1).at(col) <= height) {
            ans = isAtl(row + 1, col);
        }
        if (!ans && col < kCol - 1 && heights_.at(row).at(col + 1) <= height) {
            ans = isAtl(row, col + 1);
        }
        atl[row][col] = ans;
        on[row][col] = false;
        return ans;
    }
    bool isPac(int row, int col) {
        if (!reachable(row, col) || on[row][col]) {
            return false;
        }
        if (pac[row][col]) {
            return true;
        }
        int height = heights_.at(row).at(col);

        on[row][col] = true;
        bool ans = false;
        if (!ans && row > 0 && heights_.at(row - 1).at(col) <= height) {
            ans = isPac(row - 1, col);
        }
        if (!ans && col > 0 && heights_.at(row).at(col - 1) <= height) {
            ans = isPac(row, col - 1);
        }
        if (!ans && row < kRow - 1 && heights_.at(row + 1).at(col) <= height) {
            ans = isPac(row + 1, col);
        }
        if (!ans && col < kCol - 1 && heights_.at(row).at(col + 1) <= height) {
            ans = isPac(row, col + 1);
        }
        pac[row][col] = ans;
        on[row][col] = false;
        return ans;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        heights_ = heights;
        kRow = heights.size();
        kCol = heights.at(0).size();
        memset(atl, false, sizeof(atl));
        memset(pac, false, sizeof(pac));
        for (int i = 0; i < kRow; i++) {
            pac[i][0] = true;
            atl[i][kCol - 1] = true;
        }
        for (int j = 0; j < kCol; j++) {
            pac[0][j] = true;
            atl[kRow - 1][j] = true;
        }
        vector<vector<int>> to_return;
        for (int i = 0; i < kRow; i++) {
            for (int j = 0; j < kCol; j++) {
                if (isAtl(i,j) && isPac(i,j)) {
                    to_return.push_back({i,j});
                } 
            }
        }
        return to_return;
    }
};
// @lc code=end

