/*
 * @lc app=leetcode id=688 lang=cpp
 *
 * [688] Knight Probability in Chessboard
 *
 * https://leetcode.com/problems/knight-probability-in-chessboard/description/
 *
 * algorithms
 * Medium (51.87%)
 * Likes:    3032
 * Dislikes: 390
 * Total Accepted:    114.8K
 * Total Submissions: 212.4K
 * Testcase Example:  '3\n2\n0\n0'
 *
 * On an n x n chessboard, a knight starts at the cell (row, column) and
 * attempts to make exactly k moves. The rows and columns are 0-indexed, so the
 * top-left cell is (0, 0), and the bottom-right cell is (n - 1, n - 1).
 * 
 * A chess knight has eight possible moves it can make, as illustrated below.
 * Each move is two cells in a cardinal direction, then one cell in an
 * orthogonal direction.
 * 
 * Each time the knight is to move, it chooses one of eight possible moves
 * uniformly at random (even if the piece would go off the chessboard) and
 * moves there.
 * 
 * The knight continues moving until it has made exactly k moves or has moved
 * off the chessboard.
 * 
 * Return the probability that the knight remains on the board after it has
 * stopped moving.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3, k = 2, row = 0, column = 0
 * Output: 0.06250
 * Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight
 * on the board.
 * From each of those positions, there are also two moves that will keep the
 * knight on the board.
 * The total probability the knight stays on the board is 0.0625.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1, k = 0, row = 0, column = 0
 * Output: 1.00000
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 25
 * 0 <= k <= 100
 * 0 <= row, column <= n - 1
 * 
 * 
 */

// @lc code=start
class Solution { // Independently solved
public:
    int n;
    int k_max;
    double* dp;
    double helper(int k, int row, int col) {
        if (row < 0 || row >= n || col < 0 || col >= n) {
            return 0;
        } else if (k == 0) {
            return 1;
        }

        if (col > n / 2) {
            col = n - 1 - col;
        }

        if (row > n / 2) {
            row = n - 1 - row;
        }

        if (row > col) {
            int temp(row);
            row = col;
            col = temp;
        }

        double& curr_dp(dp[(row * (n / 2 + 1) + col) * k_max + k]);
        if (curr_dp >= 0) {
            return curr_dp;
        }
        
        curr_dp = 0;
        curr_dp += helper(k - 1, row - 1, col + 2);
        curr_dp += helper(k - 1, row - 2, col + 1);
        curr_dp += helper(k - 1, row - 2, col - 1);
        curr_dp += helper(k - 1, row - 1, col - 2);
        curr_dp += helper(k - 1, row + 1, col - 2);
        curr_dp += helper(k - 1, row + 2, col - 1);
        curr_dp += helper(k - 1, row + 2, col + 1);
        curr_dp += helper(k - 1, row + 1, col + 2);
        curr_dp /= 8;
        return curr_dp;
    }

    double knightProbability(int n_, int k, int row, int column) {
        n = n_;
        k_max = k + 1;
        int half_n(n / 2);
        vector<double> dp_v((half_n + 1) * (half_n + 1) * k_max, -1);
        dp = dp_v.data();
        return helper(k, row, column);
    }
};
// @lc code=end

