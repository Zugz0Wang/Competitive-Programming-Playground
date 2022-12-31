/*
 * @lc app=leetcode id=980 lang=cpp
 *
 * [980] Unique Paths III
 *
 * https://leetcode.com/problems/unique-paths-iii/description/
 *
 * algorithms
 * Hard (79.53%)
 * Likes:    3187
 * Dislikes: 142
 * Total Accepted:    124.1K
 * Total Submissions: 156K
 * Testcase Example:  '[[1,0,0,0],[0,0,0,0],[0,0,2,-1]]'
 *
 * You are given an m x n integer array grid where grid[i][j] could be:
 * 
 * 
 * 1 representing the starting square. There is exactly one starting
 * square.
 * 2 representing the ending square. There is exactly one ending square.
 * 0 representing empty squares we can walk over.
 * -1 representing obstacles that we cannot walk over.
 * 
 * 
 * Return the number of 4-directional walks from the starting square to the
 * ending square, that walk over every non-obstacle square exactly once.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
 * Output: 2
 * Explanation: We have the following two paths: 
 * 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
 * 2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
 * Output: 4
 * Explanation: We have the following four paths: 
 * 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
 * 2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
 * 3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
 * 4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: grid = [[0,1],[2,0]]
 * Output: 0
 * Explanation: There is no path that walks over every empty square exactly
 * once.
 * Note that the starting and ending square can be anywhere in the grid.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 20
 * 1 <= m * n <= 20
 * -1 <= grid[i][j] <= 2
 * There is exactly one starting cell and one ending cell.
 * 
 * 
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    bool visited[20][20];
    int length = 0;
    int need = 0;
    int end_row = 0;
    int end_col = 0;
    int count = 0;
    int kRow = 0;
    int kCol = 0;

    void helper(int row, int col) {
        length += 1;
        if (row < 0 || row >= kRow || col < 0 || col >= kCol || visited[row][col]) {
            length -= 1;
            return;
        }
        if (row == end_row && col == end_col) {
            //cout << length << '\n';
            if (length == need) {
                count += 1;
            }
            length -= 1;
            return;
        }
        visited[row][col] = true;
        helper(row - 1, col);
        helper(row + 1, col);
        helper(row, col - 1);
        helper(row, col + 1);
        visited[row][col] = false;
        length -= 1;
        return;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        memset(visited, false, sizeof(visited));
        
        kRow = grid.size();
        kCol = grid.at(0).size();
        int start_row = 0;
        int start_col = 0;
        for (int row = 0; row < kRow; row++) {
            for (int col = 0; col < kCol; col++) {
                const int curr = grid.at(row).at(col);
                if (curr >= 0) {
                    need += 1;
                    if (curr == 1) {
                        start_row = row;
                        start_col = col;
                    } else if (curr == 2) {
                        end_row = row;
                        end_col = col;
                    }
                } else {
                    visited[row][col] = true;
                }
            }
        }
        
        helper(start_row, start_col);
        return count;
    }
};
// @lc code=end

