/*
 * @lc app=leetcode id=1254 lang=cpp
 *
 * [1254] Number of Closed Islands
 *
 * https://leetcode.com/problems/number-of-closed-islands/description/
 *
 * algorithms
 * Medium (64.00%)
 * Likes:    2925
 * Dislikes: 89
 * Total Accepted:    133.2K
 * Total Submissions: 207K
 * Testcase Example:  '[[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]'
 *
 * Given a 2D grid consists of 0s (land) and 1s (water).  An island is a
 * maximal 4-directionally connected group of 0s and a closed island is an
 * island totally (all left, top, right, bottom) surrounded by 1s.
 * 
 * Return the number of closed islands.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: grid =
 * [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
 * Output: 2
 * Explanation: 
 * Islands in gray are closed because they are completely surrounded by water
 * (group of 1s).
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: grid = [[1,1,1,1,1,1,1],
 * [1,0,0,0,0,0,1],
 * [1,0,1,1,1,0,1],
 * [1,0,1,0,1,0,1],
 * [1,0,1,1,1,0,1],
 * [1,0,0,0,0,0,1],
 * ⁠              [1,1,1,1,1,1,1]]
 * Output: 2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= grid.length, grid[0].length <= 100
 * 0 <= grid[i][j] <=1
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution { // Original
public:
    int* mp = nullptr;
    bool* land = nullptr;
    int kRow;
    int kCol;

  
    bool checkLand(int row, int col) {
        return (row > 0 && row < kRow - 1 && col > 0 && col < kCol - 1);
    }

    int find(int a) {
        if (mp[a] == a) {
            return a;
        }
        int parent(find(mp[a]));
        mp[a] = parent;
        return parent;
    }

    void uni(int a, int b) {
        int p_a(find(a));
        int p_b(find(b));
        if (!land[p_a] || !land[p_b]) {
            land[p_a] = false;
            land[p_b] = false;
        }
        mp[p_b] = p_a;
    }

    int closedIsland(vector<vector<int>>& grid) { // Original
        kRow = grid.size();
        kCol = grid.at(0).size();
        mp = new int[kRow * kCol];
        land = new bool[kRow * kCol];
        for (int i(0); i < kRow * kCol; ++i) {
            mp[i] = i;
            land[i] = false;
        }

       
        for (int row(0); row < kRow - 1; ++row) {
            for (int col(0); col < kCol - 1; ++col) {
                if (grid.at(row).at(col) != 0) {
                    continue;
                }
                int curr_idx(row * kCol + col);
                land[curr_idx] = checkLand(row, col);
                
                int right_idx(row * kCol + col + 1);
                int down_idx((row + 1) * kCol + col);

                if (grid.at(row + 1).at(col) == 0) {
                    land[down_idx] = checkLand(row + 1, col);
                    uni(curr_idx, down_idx);
                }
                if (grid.at(row).at(col + 1) == 0) {
                    land[right_idx] = checkLand(row, col + 1);
                    uni(curr_idx, right_idx);
                }
            }
        }

        // for (int row(0); row < kRow; ++row) {
        //     for (int col(0); col < kCol; ++col) {
        //         int curr_idx(row * kCol + col);
        //         cout << mp[curr_idx] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
        //  for (int row(0); row < kRow; ++row) {
        //     for (int col(0); col < kCol; ++col) {
        //         cout << grid.at(row).at(col) << ' ';
        //     }
        //     cout << '\n';
        // }
        int count(0);
        for (int i(0); i < kRow * kCol; ++i) {
            // cout << mp[i] << '\n';
            if (mp[i] == i && land[i]) {
                // cout << i << "!\n";
                ++count;
            }
        }
        return count;
    }
};
// @lc code=end

