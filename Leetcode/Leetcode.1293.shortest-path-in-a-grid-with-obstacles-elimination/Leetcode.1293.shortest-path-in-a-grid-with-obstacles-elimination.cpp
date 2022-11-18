/*
 * @lc app=leetcode id=1293 lang=cpp
 *
 * [1293] Shortest Path in a Grid with Obstacles Elimination
 *
 * https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/description/
 *
 * algorithms
 * Hard (43.56%)
 * Likes:    2878
 * Dislikes: 53
 * Total Accepted:    131.7K
 * Total Submissions: 301.9K
 * Testcase Example:  '[[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]]\n1'
 *
 * You are given an m x n integer matrix grid where each cell is either 0
 * (empty) or 1 (obstacle). You can move up, down, left, or right from and to
 * an empty cell in one step.
 * 
 * Return the minimum number of steps to walk from the upper left corner (0, 0)
 * to the lower right corner (m - 1, n - 1) given that you can eliminate at
 * most k obstacles. If it is not possible to find such walk return -1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
 * Output: 6
 * Explanation: 
 * The shortest path without eliminating any obstacle is 10.
 * The shortest path with one obstacle elimination at position (3,2) is 6. Such
 * path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[0,1,1],[1,1,1],[1,0,0]], k = 1
 * Output: -1
 * Explanation: We need to eliminate at least two obstacles to find such a
 * walk.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 40
 * 1 <= k <= m * n
 * grid[i][j] is either 0 or 1.
 * grid[0][0] == grid[m - 1][n - 1] == 0
 * 
 * 
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
class Solution {
public:
    struct node {
        int x;
        int y;
        int length;
        int remain;
        node (int x0, int y0, int l, int r): x(x0), y(y0), length(l), remain(r) {}
    };
    int visited[40][40] = {-1};
    int shortestPath(vector<vector<int>>& grid, int k) {
        memset(visited, -1, sizeof(visited));
        const int kRow = grid.size();
        const int kCol = grid.at(0).size();
        queue<node> waitlist;
        waitlist.push(node(0,0,0,k));
        while (!waitlist.empty()) {
            node curr = waitlist.front();
            waitlist.pop();
            int x = curr.x;
            int y = curr.y;
            int length = curr.length;
            int remain = curr.remain;

            if(x<0 || y<0 || x>=kRow || y>=kCol){
                continue;
            }

            if (grid.at(x).at(y) == 1) {
                if (remain > 0) {
                    remain--;
                } else {
                    continue;
                }
            }

            if (x == kRow - 1 && y == kCol - 1) {
                return length;
            }

            if (visited[x][y] != -1 && visited[x][y] >= remain) {
                continue;
            }
            visited[x][y] = remain;

            if (x + 1 < kRow) waitlist.push(node(x + 1, y, length + 1, remain));
            
            if (y + 1 < kCol) waitlist.push(node(x, y + 1, length + 1, remain));

            if (x > 0) waitlist.push(node(x - 1, y, length + 1, remain));

            if (y > 0) waitlist.push(node(x, y - 1, length + 1, remain));
        }
        return -1;
    }
};
// @lc code=end

