/*
 * @lc app=leetcode id=1337 lang=cpp
 *
 * [1337] The K Weakest Rows in a Matrix
 *
 * https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/description/
 *
 * algorithms
 * Easy (73.49%)
 * Likes:    3001
 * Dislikes: 176
 * Total Accepted:    225.6K
 * Total Submissions: 311.2K
 * Testcase Example:  '[[1,1,0,0,0],[1,1,1,1,0],[1,0,0,0,0],[1,1,0,0,0],[1,1,1,1,1]]\n3'
 *
 * You are given an m x n binary matrix mat of 1's (representing soldiers) and
 * 0's (representing civilians). The soldiers are positioned in front of the
 * civilians. That is, all the 1's will appear to the left of all the 0's in
 * each row.
 * 
 * A row i is weaker than a row j if one of the following is true:
 * 
 * 
 * The number of soldiers in row i is less than the number of soldiers in row
 * j.
 * Both rows have the same number of soldiers and i < j.
 * 
 * 
 * Return the indices of the k weakest rows in the matrix ordered from weakest
 * to strongest.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: mat = 
 * [[1,1,0,0,0],
 * ⁠[1,1,1,1,0],
 * ⁠[1,0,0,0,0],
 * ⁠[1,1,0,0,0],
 * ⁠[1,1,1,1,1]], 
 * k = 3
 * Output: [2,0,3]
 * Explanation: 
 * The number of soldiers in each row is: 
 * - Row 0: 2 
 * - Row 1: 4 
 * - Row 2: 1 
 * - Row 3: 2 
 * - Row 4: 5 
 * The rows ordered from weakest to strongest are [2,0,3,1,4].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: mat = 
 * [[1,0,0,0],
 * ⁠[1,1,1,1],
 * ⁠[1,0,0,0],
 * ⁠[1,0,0,0]], 
 * k = 2
 * Output: [0,2]
 * Explanation: 
 * The number of soldiers in each row is: 
 * - Row 0: 1 
 * - Row 1: 4 
 * - Row 2: 1 
 * - Row 3: 1 
 * The rows ordered from weakest to strongest are [0,2,3,1].
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == mat.length
 * n == mat[i].length
 * 2 <= n, m <= 100
 * 1 <= k <= m
 * matrix[i][j] is either 0 or 1.
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int count(int row) {
        int head = 0;
        int tail = kCol;
        while (head < tail) {
            int mid_idx = (head + tail) / 2;
            int mid_val = mat0.at(row).at(mid_idx);
            if (mid_val == 0) {
                if (mid_idx == 0) {
                    return 0;
                }
                int prev_val = mat0.at(row).at(mid_idx - 1);
                if (prev_val == 1) {
                    return mid_idx;
                } else {
                    tail = mid_idx;
                }
            } else {
                head = mid_idx + 1;
            }
        }
        return tail;
    }

    vector<vector<int>> mat0;
    int kRow;
    int kCol;
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        mat0 = mat;
        kRow = mat.size();
        kCol = mat.at(0).size();
        vector<pair<int, int>> v;
        for (int row = 0; row < kRow; row++) {
            
            pair<int, int> p(count(row), row);
            
            
            v.push_back(p);
        }
        sort(v.begin(), v.end());
       
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            
            ans.push_back(v.at(i).second);
        }
        return ans;
    }
};
// @lc code=end

