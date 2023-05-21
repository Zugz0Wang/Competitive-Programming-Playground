/*
 * @lc app=leetcode id=934 lang=cpp
 *
 * [934] Shortest Bridge
 *
 * https://leetcode.com/problems/shortest-bridge/description/
 *
 * algorithms
 * Medium (53.52%)
 * Likes:    3206
 * Dislikes: 142
 * Total Accepted:    112.1K
 * Total Submissions: 208.3K
 * Testcase Example:  '[[0,1],[1,0]]'
 *
 * You are given an n x n binary matrix grid where 1 represents land and 0
 * represents water.
 * 
 * An island is a 4-directionally connected group of 1's not connected to any
 * other 1's. There are exactly two islands in grid.
 * 
 * You may change 0's to 1's to connect the two islands to form one island.
 * 
 * Return the smallest number of 0's you must flip to connect the two
 * islands.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[0,1],[1,0]]
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
 * Output: 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == grid.length == grid[i].length
 * 2 <= n <= 100
 * grid[i][j] is either 0 or 1.
 * There are exactly two islands in grid.
 * 
 * 
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) { // Independently solved
        
        const size_t kRow(grid.size());
        const size_t kCol(grid.at(0).size());
        bool found(false);

        // Find the start point of one of the islands.

        size_t start(0);
        for (size_t row(0); row < kRow; row++) {
            for (size_t col(0); col < kCol; col++) {
                if (grid.at(row).at(col) == 1) {
                    found = true;
                    start = row * kCol + col;
                    break;
                }
            }
            if (found) {
                break;
            }
        }
        vector<vector<bool>> visited(kRow, vector<bool>(kCol, false));

        // Find all of the points of the first island.

        queue<size_t> q;
        visited.at(start / kCol).at(start % kRow) = true;
        q.push(start);
        queue<size_t> q1;

        while (!q.empty()) {
            size_t curr(q.front());
            q.pop();
            q1.push(curr);
            // cout << curr << ' ';
            size_t r(curr / kCol);
            size_t c(curr % kCol);


            size_t nr(r);
            size_t nc(c);


            nr = r - 1;
            nc = c;
            if (r > 0 && grid.at(nr).at(nc) == 1 && !visited.at(nr).at(nc)) {
                q.push((nr) * kCol + nc);
                visited.at(nr).at(nc) = true;
            }

            nr = r + 1;
            nc = c;
            if (nr < kRow && grid.at(nr).at(nc) == 1 && !visited.at(nr).at(nc)) {
                q.push((nr) * kCol + nc);
                visited.at(nr).at(nc) = true;
            }

            nr = r;
            nc = c - 1;
            if (c > 0 && grid.at(nr).at(nc) == 1 && !visited.at(nr).at(nc)) {
                q.push((nr) * kCol + nc);
                visited.at(nr).at(nc) = true;
            }

            nr = r;
            nc = c + 1;
            if (nc < kCol && grid.at(nr).at(nc) == 1 && !visited.at(nr).at(nc)) {
                q.push((nr) * kCol + nc);
                visited.at(nr).at(nc) = true;
            }
        }

        // Using BFS with multiple starting points to find the distance.

        int ans(0);
        found = false;
        while (!q1.empty()) {
            size_t size(q1.size());
            for (size_t i(0); i < size; ++i) {
                size_t curr(q1.front());
                q1.pop();
                
                size_t r(curr / kCol);
                size_t c(curr % kCol);


                size_t nr(r);
                size_t nc(c);

                nr = r - 1;
                nc = c;
                if (r > 0 && !visited.at(nr).at(nc)) {
                    if (grid.at(nr).at(nc) == 0) {
                        q1.push((nr) * kCol + nc);
                        visited.at(nr).at(nc) = true;
                    } else {
                        return ans;
                    }
                }

                nr = r + 1;
                nc = c;
                if (nr < kRow && !visited.at(nr).at(nc)) {
                    if (grid.at(nr).at(nc) == 0) {
                        q1.push((nr) * kCol + nc);
                        visited.at(nr).at(nc) = true;
                    } else {
                        return ans;
                    }
                }

                nr = r;
                nc = c - 1;
                if (c > 0 && !visited.at(nr).at(nc)) {
                    if (grid.at(nr).at(nc) == 0) {
                        q1.push((nr) * kCol + nc);
                        visited.at(nr).at(nc) = true;
                    } else {
                        return ans;
                    }
                }

                nr = r;
                nc = c + 1;
                if (nc < kCol && !visited.at(nr).at(nc)) {
                    if (grid.at(nr).at(nc) == 0) {
                        q1.push((nr) * kCol + nc);
                        visited.at(nr).at(nc) = true;
                    } else {
                        return ans;
                    }
                }
            }
            ++ans;
        }
        return -1;
    }
};
// @lc code=end

