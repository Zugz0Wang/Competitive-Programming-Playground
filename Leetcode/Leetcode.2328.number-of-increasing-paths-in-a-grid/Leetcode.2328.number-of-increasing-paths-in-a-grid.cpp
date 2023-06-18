/*
 * @lc app=leetcode id=2328 lang=cpp
 *
 * [2328] Number of Increasing Paths in a Grid
 *
 * https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/description/
 *
 * algorithms
 * Hard (47.24%)
 * Likes:    829
 * Dislikes: 19
 * Total Accepted:    20.3K
 * Total Submissions: 40.9K
 * Testcase Example:  '[[1,1],[3,4]]'
 *
 * You are given an m x n integer matrix grid, where you can move from a cell
 * to any adjacent cell in all 4 directions.
 * 
 * Return the number of strictly increasing paths in the grid such that you can
 * start from any cell and end at any cell. Since the answer may be very large,
 * return it modulo 10^9 + 7.
 * 
 * Two paths are considered different if they do not have exactly the same
 * sequence of visited cells.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[1,1],[3,4]]
 * Output: 8
 * Explanation: The strictly increasing paths are:
 * - Paths with length 1: [1], [1], [3], [4].
 * - Paths with length 2: [1 -> 3], [1 -> 4], [3 -> 4].
 * - Paths with length 3: [1 -> 3 -> 4].
 * The total number of paths is 4 + 3 + 1 = 8.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[1],[2]]
 * Output: 3
 * Explanation: The strictly increasing paths are:
 * - Paths with length 1: [1], [2].
 * - Paths with length 2: [1 -> 2].
 * The total number of paths is 2 + 1 = 3.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 1000
 * 1 <= m * n <= 10^5
 * 1 <= grid[i][j] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution { // Learned
    public:
    const int mod = 1e9 + 7;
    vector<vector<int>> grid;
    vector<int> dp;
    size_t M;
    size_t N;
    int helper(size_t i0, size_t j0) {
        const int curr(grid.at(i0).at(j0));
        int& curr_dp(dp.at(i0 * N + j0));
        if (curr_dp > 0) {
            return curr_dp;
        }
        curr_dp = 1;
        
        size_t i(0);
        size_t j(0);

        i = i0;
        j = j0 + 1;
        if (j < N && grid.at(i).at(j) > curr) {
            curr_dp = (curr_dp + helper(i, j)) % mod;
        }

        i = i0 + 1;
        j = j0;

        if (i < M && grid.at(i).at(j) > curr) {
            curr_dp = (curr_dp + helper(i, j)) % mod;
        }

        
        i = i0;
        j = j0 - 1;
        if (j0 > 0 && grid.at(i).at(j) > curr) {
            curr_dp = (curr_dp + helper(i, j)) % mod;
        }
        
        i = i0 - 1;
        j = j0;
        if (i0 > 0 && grid.at(i).at(j) > curr) {
            curr_dp = (curr_dp + helper(i, j)) % mod;
        }
        return curr_dp;
    }
    int countPaths(vector<vector<int>>& grid_) {
        grid = grid_;
        M = grid.size();
        N = grid.at(0).size();
        
        dp.resize(M * N, -1);
        int total(0);
        for (size_t i(0); i < M; ++i) {
            for (size_t j(0); j < N; ++j) {
                total = (total + helper(i, j)) % mod;
            }
        }
        return total;
    }
};
// My overthinked version
// class Solution { 
// public:
//     const int mod = 1e9 + 7;
//     int countPaths(vector<vector<int>>& grid) {
//         const size_t M(grid.size());
//         const size_t N(grid.at(0).size());
//         vector<int> dp(M * N, -1);

//         vector<size_t> indices(M * N);
//         for (size_t i(0); i < M * N; ++i) {
//            dp.at(i) = i;
//         }

//         const auto compare = [N, grid](size_t a, size_t b) {
//             return grid.at(a / N).at(a % N) < grid.at(b / N).at(b % N);
//         };
//         sort(indices.begin(), indices.end(), compare);
//         int total(0);
//         for (size_t idx : indices) {
//             size_t i0(idx / N);
//             size_t j0(idx % N);
            
//             size_t i(0);
//             size_t j(0);

//             const int curr(grid.at(i0).at(j0));
//             int& curr_dp(dp.at(i0 * N + j0));
//             size_t dp_idx(0);

//             curr_dp = 1;

//             i = i0;
//             j = j0 + 1;
//             if (j < N && dp.at(i * N + j) >= 0 && grid.at(i).at(j) < curr) {
//                 curr_dp = (curr_dp + dp.at(i * N + j)) % mod;
//             }

//             i = i0 + 1;
//             j = j0;

//             if (i < M && dp.at(i * N + j) >= 0 && grid.at(i).at(j) < curr) {
//                 curr_dp = (curr_dp + dp.at(i * N + j)) % mod;
//             }

            
//             i = i0;
//             j = j0 - 1;

//             if (j0 > 0 && dp.at(i * N + j) >= 0 && grid.at(i).at(j) < curr) {
//                 curr_dp = (curr_dp + dp.at(i * N + j)) % mod;
//             }
            
//             i = i0 - 1;
//             j = j0;
//             if (i0 > 0 && dp.at(i * N + j) >= 0 && grid.at(i).at(j) < curr) {
//                 curr_dp = (curr_dp + dp.at(i * N + j)) % mod;
//             }

//             total = (total + curr_dp) % mod;
//         }
       
//         return total;
//     }
// };
// @lc code=end

