/*
 * @lc app=leetcode id=1020 lang=cpp
 *
 * [1020] Number of Enclaves
 *
 * https://leetcode.com/problems/number-of-enclaves/description/
 *
 * algorithms
 * Medium (64.06%)
 * Likes:    2442
 * Dislikes: 43
 * Total Accepted:    105.1K
 * Total Submissions: 158.7K
 * Testcase Example:  '[[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]'
 *
 * You are given an m x n binary matrix grid, where 0 represents a sea cell and
 * 1 represents a land cell.
 * 
 * A move consists of walking from one land cell to another adjacent
 * (4-directionally) land cell or walking off the boundary of the grid.
 * 
 * Return the number of land cells in grid for which we cannot walk off the
 * boundary of the grid in any number of moves.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
 * Output: 3
 * Explanation: There are three 1s that are enclosed by 0s, and one 1 that is
 * not enclosed because its on the boundary.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
 * Output: 0
 * Explanation: All 1s are either on the boundary or can reach the
 * boundary.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 500
 * grid[i][j] is either 0 or 1.
 * 
 * 
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution { // LC.1254; Independently solved.
public:
    int* mp = nullptr;
    bool* land = nullptr;
    int kRow;
    int kCol;

    bool checkLand(int row, int col) {
        return (row > 0 && row < kRow - 1 && col > 0 && col < kCol - 1);
    }

    int find(int a) { // Find which group a belongs.
        if (mp[a] == a) {
            return a;
        }
        int parent(find(mp[a]));
        mp[a] = parent;
        return parent;
    }

    void uni(int a, int b) { // Merge two groups together
        int p_a(find(a));
        int p_b(find(b));
        if (!land[p_a] || !land[p_b]) { // If the union involves non-land land, mark both as non-land land
            land[p_a] = false;
            land[p_b] = false;
        }
        mp[p_b] = p_a;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        kRow = grid.size();
        kCol = grid.at(0).size();
        mp = new int[kRow * kCol];
        land = new bool[kRow * kCol];
        for (int i(0); i < kRow * kCol; ++i) { // Initialize
            mp[i] = i;
            land[i] = false;
        }

        for (int row(0); row < kRow - 1; ++row) {
            for (int col(0); col < kCol - 1; ++col) { // Loop through all the block, and merge if two neighbor blocks are both 0s
                if (grid.at(row).at(col) != 1) {
                    continue;
                }
                int curr_idx(row * kCol + col);
                land[curr_idx] = checkLand(row, col);
                
                int right_idx(row * kCol + col + 1);
                int down_idx((row + 1) * kCol + col);

                if (grid.at(row + 1).at(col) == 1) {
                    land[down_idx] = checkLand(row + 1, col);
                    uni(curr_idx, down_idx);
                }
                if (grid.at(row).at(col + 1) == 1) {
                    land[right_idx] = checkLand(row, col + 1);
                    uni(curr_idx, right_idx);
                }
            }
        }

        int count(0);
        for (int i(0); i < kRow * kCol; ++i) {
            // cout << mp[i] << '\n';
            if (land[find(i)]) { // Check whether the group is a land group
                // cout << i << "!\n";
                ++count;
            }
        }

        delete[] mp;
        delete[] land;

        mp = nullptr;
        land = nullptr;

        return count;
    }
};
// @lc code=end

