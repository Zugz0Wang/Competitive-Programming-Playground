/*
 * @lc app=leetcode id=1162 lang=cpp
 *
 * [1162] As Far from Land as Possible
 *
 * https://leetcode.com/problems/as-far-from-land-as-possible/description/
 *
 * algorithms
 * Medium (48.38%)
 * Likes:    2526
 * Dislikes: 71
 * Total Accepted:    85K
 * Total Submissions: 174.8K
 * Testcase Example:  '[[1,0,1],[0,0,0],[1,0,1]]'
 *
 * Given an n x n grid containing only values 0 and 1, where 0 represents water
 * and 1 represents land, find a water cell such that its distance to the
 * nearest land cell is maximized, and return the distance. If no land or water
 * exists in the grid, return -1.
 * 
 * The distance used in this problem is the Manhattan distance: the distance
 * between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
 * Output: 2
 * Explanation: The cell (1, 1) is as far as possible from all the land with
 * distance 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
 * Output: 4
 * Explanation: The cell (2, 2) is as far as possible from all the land with
 * distance 4.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == grid.length
 * n == grid[i].length
 * 1 <= n <= 100
 * grid[i][j] is 0 or 1
 * 
 * 
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start

struct pos {
    int x;
    int y;
    int dis;
    pos(int x_, int y_, int dis_ = 0): x(x_), y(y_), dis(dis_) {}
};

class Solution {
public:
    bool visited[100][100];
    int maxDistance(vector<vector<int>>& grid) {
        memset(visited, false, sizeof(visited));
        const int kRow = grid.size();
        const int kCol = grid.at(0).size();
        queue<pos> wait;
        int count = 0;
        for (int row = 0; row < kRow; row++) {
            for (int col = 0; col < kCol; col++) {
                if (grid.at(row).at(col) > 0) {
                    wait.push(pos(row, col, 0));
                    visited[row][col] = true;
                    count += 1;
                }
            }
        }
        if (count == kRow * kCol || count == 0) {
            return -1;
        }
        int ans = 0;
       
        while (wait.size() > 0) {
            pos curr = wait.front();
            wait.pop();
            int x = curr.x;
            int y = curr.y;
            int dis = curr.dis;
            ans = dis;
            if (x > 0 && visited[x - 1][y] == false) {
                wait.push(pos(x - 1, y, dis + 1));
                visited[x - 1][y] = true;
            }
            if (x < kRow - 1 && visited[x + 1][y] == false) {
                wait.push(pos(x + 1, y, dis + 1));
                visited[x + 1][y] = true;
            }
            if (y > 0 && visited[x][y - 1] == false) {
                wait.push(pos(x, y - 1, dis + 1));
                visited[x][y - 1] = true;
            }
            if (y < kCol - 1 && visited[x][y + 1] == false) {
                wait.push(pos(x, y + 1, dis + 1));
                visited[x][y + 1] = true;
            }
            count++;
        }
        return ans;
    }
};
// @lc code=end

