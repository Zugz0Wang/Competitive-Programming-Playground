/*
 * @lc app=leetcode id=1351 lang=cpp
 *
 * [1351] Count Negative Numbers in a Sorted Matrix
 *
 * https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/
 *
 * algorithms
 * Easy (75.15%)
 * Likes:    2966
 * Dislikes: 90
 * Total Accepted:    222.2K
 * Total Submissions: 295K
 * Testcase Example:  '[[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]'
 *
 * Given a m x n matrix grid which is sorted in non-increasing order both
 * row-wise and column-wise, return the number of negative numbers in grid.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
 * Output: 8
 * Explanation: There are 8 negatives number in the matrix.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[3,2],[1,0]]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 100
 * -100 <= grid[i][j] <= 100
 * 
 * 
 * 
 * Follow up: Could you find an O(n + m) solution?
 */

// @lc code=start
class Solution { // Independently solved
public:
    vector<vector<int>> grid0;
    int kRow;
    int kCol;
    // int count(int row0, int row1, int col0, int col1) {
    //     int head_r = 0;
    //     int tail_r = row1 - row0;
    //     int head_c = 0;
    //     int tail_c = col1 - col0;
    //     bool found = false;
    //     int r = -1;
    //     int c = -1;
    //     while (head_r < tail_r && head_c < tail_c) {
    //         int mid_r = (head_r + tail_r) / 2;
    //         int mid_c = (head_c + tail_c) / 2;
    //         int mid_val = grid0.at(row0 + mid_r).at(col0 + mid_c);
    //         if (mid_val < 0) {
    //             if (mid_r == 0 || mid_c == 0) {
    //                 r = mid_r;
    //                 c = mid_c;
    //                 found = true;
    //                 break;
    //             }
    //             int prev_c = grid0.at(row0 + mid_r).at(col0 + mid_c - 1);
    //             int prev_r = grid0.at(row0 + mid_r - 1).at(col0 + mid_c);
    //             if (prev_c >= 0 && prev_r >= 0) {
    //                 r = mid_r;
    //                 c = mid_c;
    //                 found = true;
    //                 break;
    //             } else {
    //                 tail_r = mid_r;
    //                 tail_c = mid_c;
    //             }
    //         } else {
    //             head_r = mid_r + 1;
    //             head_c = mid_c + 1;
    //         }
    //     }
    //     if (!found) {
    //         return 0;
    //     } else {
            
    //         return (col1 - c) * (row1 - r) + 
    //             count(row0 + r, row1, col0, col0 + c) +
    //             count(row0, row0 + r, col0 + c, col1);
    //     }
    // }
    int foundCol(int row, int head, int tail) {
        //cout << row << '\n';
        while (head < tail) {
            int mid_idx = (head + tail) / 2;
            int mid_val = grid0.at(row).at(mid_idx);
            
            if (mid_val < 0) {
                if (mid_idx == 0) {
                    return 0;
                }
                int prev_val = grid0.at(row).at(mid_idx - 1);
                if (prev_val >= 0) {
                    return mid_idx;
                } else {
                    tail = mid_idx;
                }
            } else {
                head = mid_idx + 1;
            }
        }
        return kCol;
    }

    int foundRow(int col, int head, int tail) {
        //cout << col << '\n';
        while (head < tail) {
            int mid_idx = (head + tail) / 2;
            int mid_val = grid0.at(mid_idx).at(col);
            
            if (mid_val < 0) {
                if (mid_idx == 0) {
                    return 0;
                }
                int prev_val = grid0.at(mid_idx - 1).at(col);
                if (prev_val >= 0) {
                    return mid_idx;
                } else {
                    tail = mid_idx;
                }
            } else {
                head = mid_idx + 1;
            }
        }
        return kCol;
    }

    int countNegatives(vector<vector<int>>& grid) {
        grid0 = grid;
        kRow = grid.size();
        kCol = grid.at(0).size();

        int prev_row = kRow;
        int count = 0;
        int col_idx = 0;
        int row_idx = 0;
        while (prev_row > 0 && col_idx < kCol) {
            col_idx = foundCol(prev_row - 1, col_idx, kCol);
            if (col_idx >= kCol) {
                break;
            }
            row_idx = foundRow(col_idx, 0, prev_row);
            
            count += (kCol - col_idx) * (prev_row - row_idx);
           
            prev_row = row_idx;
        }
        
        return count;
    }
    // [[3,2],[1,0]]
    // [[4,3,2,-1]]
};
// @lc code=end

