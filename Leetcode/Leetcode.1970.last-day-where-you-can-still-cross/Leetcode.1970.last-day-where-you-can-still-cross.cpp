/*
 * @lc app=leetcode id=1970 lang=cpp
 *
 * [1970] Last Day Where You Can Still Cross
 *
 * https://leetcode.com/problems/last-day-where-you-can-still-cross/description/
 *
 * algorithms
 * Hard (48.93%)
 * Likes:    1389
 * Dislikes: 26
 * Total Accepted:    35.4K
 * Total Submissions: 57.9K
 * Testcase Example:  '2\n2\n[[1,1],[2,1],[1,2],[2,2]]'
 *
 * There is a 1-based binary matrix where 0 represents land and 1 represents
 * water. You are given integers row and col representing the number of rows
 * and columns in the matrix, respectively.
 * 
 * Initially on day 0, the entire matrix is land. However, each day a new cell
 * becomes flooded with water. You are given a 1-based 2D array cells, where
 * cells[i] = [ri, ci] represents that on the i^th day, the cell on the ri^th
 * row and ci^th column (1-based coordinates) will be covered with water (i.e.,
 * changed to 1).
 * 
 * You want to find the last day that it is possible to walk from the top to
 * the bottom by only walking on land cells. You can start from any cell in the
 * top row and end at any cell in the bottom row. You can only travel in the
 * four cardinal directions (left, right, up, and down).
 * 
 * Return the last day where it is possible to walk from the top to the bottom
 * by only walking on land cells.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]
 * Output: 2
 * Explanation: The above image depicts how the matrix changes each day
 * starting from day 0.
 * The last day where it is possible to cross from top to bottom is on day 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: row = 2, col = 2, cells = [[1,1],[1,2],[2,1],[2,2]]
 * Output: 1
 * Explanation: The above image depicts how the matrix changes each day
 * starting from day 0.
 * The last day where it is possible to cross from top to bottom is on day 1.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: row = 3, col = 3, cells =
 * [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]
 * Output: 3
 * Explanation: The above image depicts how the matrix changes each day
 * starting from day 0.
 * The last day where it is possible to cross from top to bottom is on day
 * 3.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= row, col <= 2 * 10^4
 * 4 <= row * col <= 2 * 10^4
 * cells.length == row * col
 * 1 <= ri <= row
 * 1 <= ci <= col
 * All the values of cells are unique.
 * 
 * 
 */

// @lc code=start
class Solution { // Independently solved(verified through tags)
public:
    int row;
    int col;
    int* uf;

    int find(int i) {
        int& curr(uf[i]);
        if (curr == -1 || curr == i) {
            return curr;
        }
        curr = find(curr);
        return curr;
    }

    bool uni(int a, int b) {
        int p_a(find(a));
        int p_b(find(b));
        if (p_a == p_b) {
            return false;
        }
        uf[p_b] = p_a;
        return true;
    }

    int latestDayToCross(int r_, int c_, vector<vector<int>>& cells) {
        row = r_;
        col = c_;
        int uf_max(row * col);
        uf = new int[uf_max + 2];
        for (int i(0); i < uf_max; ++i) {
            uf[i] = -1;
        }
        uf[uf_max] = uf_max;
        uf[uf_max + 1] = uf_max + 1;
        
        const size_t size(cells.size());
        
        for (size_t i(size - 1); i < size; --i) {
            const vector<int>& curr(cells.at(i));
            int r(curr.at(0) - 1);
            int c(curr.at(1) - 1);
            int idx0(r * col + c);
            if (r == 0) {
                uf[idx0] = uf_max;
            } else if (r == row - 1) {
                uf[idx0] = uf_max + 1;
            } else {
                uf[idx0] = idx0;
            }

            int idx;
            int r1;
            int c1;

            r1 = r - 1;
            c1 = c;
            idx = r1 * col + c1;
            if (r1 >= 0 && uf[idx] >= 0) {
                uni(idx0, idx);
            }
            
            r1 = r + 1;
            c1 = c;
            idx = r1 * col + c1;
            if (r1 < row && uf[idx] >= 0) {
                uni(idx0, idx);
            }

            r1 = r;
            c1 = c - 1;
            idx = r1 * col + c1;
            if (c1 >= 0 && uf[idx] >= 0) {
                uni(idx0, idx);
            }

            r1 = r;
            c1 = c + 1;
            idx = r1 * col + c1;
            if (c1 < col && uf[idx] >= 0) {
                uni(idx0, idx);
            }

            if (find(uf_max) == find(uf_max + 1)) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

