/*
 * @lc app=leetcode id=363 lang=cpp
 *
 * [363] Max Sum of Rectangle No Larger Than K
 *
 * https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/description/
 *
 * algorithms
 * Hard (40.22%)
 * Likes:    2133
 * Dislikes: 113
 * Total Accepted:    83.5K
 * Total Submissions: 206.2K
 * Testcase Example:  '[[1,0,1],[0,-2,3]]\n2'
 *
 * Given an m x n matrix matrix and an integer k, return the max sum of a
 * rectangle in the matrix such that its sum is no larger than k.
 * 
 * It is guaranteed that there will be a rectangle with a sum no larger than
 * k.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[1,0,1],[0,-2,3]], k = 2
 * Output: 2
 * Explanation: Because the sum of the blue rectangle [[0, 1], [-2, 3]] is 2,
 * and 2 is the max number no larger than k (k = 2).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[2,2,-1]], k = 3
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 100
 * -100 <= matrix[i][j] <= 100
 * -10^5 <= k <= 10^5
 * 
 * 
 * 
 * Follow up: What if the number of rows is much larger than the number of
 * columns?
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int sum[101][101];
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        const int kSizeM = matrix.size();
        const int kSizeN = matrix.at(0).size();
        memset(sum, 0, sizeof(sum));
        sum[1][1] = matrix.at(0).at(0);
        for (int i = 2; i < kSizeM + 1; i++) {
            sum[i][1] = sum[i - 1][1] + matrix.at(i - 1).at(0);
        }
        for (int j = 2; j < kSizeN + 1; j++) {
            sum[1][j] = sum[1][j - 1] + matrix.at(0).at(j - 1);
        }
        for (int i = 2; i < kSizeM + 1; i++) {
            for (int j = 2; j < kSizeN + 1; j++) {
                sum[i][j] = matrix.at(i - 1).at(j - 1) + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            }
        }
        int to_return = 0;
        bool start = false;
        for (int i0 = 0; i0 < kSizeM; i0++) {
            for (int j0 = 0; j0 < kSizeN; j0++) {
                for (int i1 = i0 + 1; i1 < kSizeM + 1; i1++) {
                    for (int j1 = j0 + 1; j1 < kSizeN + 1; j1++) {
                        int total = sum[i1][j1] - sum[i0][j1] - sum[i1][j0] + sum[i0][j0];
                        if (start) {
                            if (total <= k && total > to_return) {
                                to_return = total;
                            }
                        } else {
                            if (total <= k) {
                                to_return = total;
                                start = true;
                            }
                        }
                    }
                }
            } 
        }
        return to_return;
    }
};
// @lc code=end

