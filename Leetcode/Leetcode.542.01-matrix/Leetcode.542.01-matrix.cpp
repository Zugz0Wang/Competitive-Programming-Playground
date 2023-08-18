/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 *
 * https://leetcode.com/problems/01-matrix/description/
 *
 * algorithms
 * Medium (43.99%)
 * Likes:    8633
 * Dislikes: 382
 * Total Accepted:    469.4K
 * Total Submissions: 990.1K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * Given an m x n binary matrix mat, return the distance of the nearest 0 for
 * each cell.
 * 
 * The distance between two adjacent cells is 1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
 * Output: [[0,0,0],[0,1,0],[0,0,0]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
 * Output: [[0,0,0],[0,1,0],[1,2,1]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 10^4
 * 1 <= m * n <= 10^4
 * mat[i][j] is either 0 or 1.
 * There is at least one 0 in mat.
 * 
 * 
 */

// @lc code=start
class Solution { // Independently solved
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        const size_t M(mat.size());
        const size_t N(mat.at(0).size());
        vector<vector<int>> ans(M, vector<int>(N,-2));
        queue<int> q;
        for (size_t r(0); r < M; ++r) {
            for (size_t c(0); c < N; ++c) {
                if (mat.at(r).at(c) == 0) {
                    q.push(r * N + c);
                    ans.at(r).at(c) = 0;
                }
            }
        }
        int dis(1);
        while (!q.empty()) {
            const size_t size(q.size());
            // cout << '\n';
            for (size_t i(0); i < size; ++i) {
                int curr_key(q.front());
                q.pop();
                size_t r(curr_key / N);
                size_t c(curr_key % N);

                size_t nr;
                size_t nc;
                // cout << r << ' ' << c << ' ';
                nr = r - 1;
                nc = c;
                if (nr < M && ans.at(nr).at(nc) == -2) {
                    ans.at(nr).at(nc) = dis;
                    q.push(nr * N + nc);
                }

                nr = r + 1;
                nc = c;
                if (nr < M && ans.at(nr).at(nc) == -2) {
                    ans.at(nr).at(nc) = dis;
                    q.push(nr * N + nc);
                }

                nr = r;
                nc = c - 1;
                if (nc < N && ans.at(nr).at(nc) == -2) {
                    ans.at(nr).at(nc) = dis;
                    q.push(nr * N + nc);
                }

                nr = r;
                nc = c + 1;
                if (nc < N && ans.at(nr).at(nc) == -2) {
                    ans.at(nr).at(nc) = dis;
                    q.push(nr * N + nc);
                }
            }
            ++dis;
        }
        return ans;
    }
};
// @lc code=end

