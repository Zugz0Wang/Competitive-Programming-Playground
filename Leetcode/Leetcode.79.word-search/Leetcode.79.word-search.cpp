/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (39.98%)
 * Likes:    12034
 * Dislikes: 487
 * Total Accepted:    1.2M
 * Total Submissions: 2.9M
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given an m x n grid of characters board and a string word, return true if
 * word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cells,
 * where adjacent cells are horizontally or vertically neighboring. The same
 * letter cell may not be used more than once.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "ABCCED"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "SEE"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "ABCB"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == board.length
 * n = board[i].length
 * 1 <= m, n <= 6
 * 1 <= word.length <= 15
 * board and word consists of only lowercase and uppercase English letters.
 * 
 * 
 * 
 * Follow up: Could you use search pruning to make your solution faster with a
 * larger board?
 * 
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    int kRow = 0, kCol = 0;
    int kLength = 0;
    char board[7][7];
    string word;
    bool helper(int row, int col, int idx) {
        if (idx >= kLength) {
            return true;
        }
        char curr = board[row][col];
        board[row][col] = '0';
        char need = word.at(idx);
        if (row - 1 >= 0 && board[row - 1][col] == need && helper(row - 1, col, idx + 1)) {
            return true;
        }
        if (row + 1 < kRow && board[row + 1][col] == need && helper(row + 1, col, idx + 1)) {
            return true;
        }
        if (col - 1 >= 0 && board[row][col - 1] == need && helper(row, col - 1, idx + 1)) {
            return true;
        }
        if (col + 1 >= 0 && board[row][col + 1] == need && helper(row, col + 1, idx + 1)) {
            return true;
        }
        board[row][col] = curr;
        return false;
    }
    bool exist(vector<vector<char>>& b, string w) {
        kRow = b.size();
        kCol = b.at(0).size();
        kLength = w.size();
        word = w;
        for (int row = 0; row < kRow; row++) {
            for (int col = 0; col < kCol; col++) {
                board[row][col] = b.at(row).at(col);
            }
        }
        char first = word.at(0);
        for (int row = 0; row < kRow; row++) {
            for (int col = 0; col < kCol; col++) {
                if (board[row][col] == first && helper(row, col, 1)) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end

