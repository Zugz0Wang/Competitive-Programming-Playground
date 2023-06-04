/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 *
 * https://leetcode.com/problems/number-of-provinces/description/
 *
 * algorithms
 * Medium (62.94%)
 * Likes:    7709
 * Dislikes: 295
 * Total Accepted:    637.1K
 * Total Submissions: 993.3K
 * Testcase Example:  '[[1,1,0],[1,1,0],[0,0,1]]'
 *
 * There are n cities. Some of them are connected, while some are not. If city
 * a is connected directly with city b, and city b is connected directly with
 * city c, then city a is connected indirectly with city c.
 * 
 * A province is a group of directly or indirectly connected cities and no
 * other cities outside of the group.
 * 
 * You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the
 * i^th city and the j^th city are directly connected, and isConnected[i][j] =
 * 0 otherwise.
 * 
 * Return the total number of provinces.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 200
 * n == isConnected.length
 * n == isConnected[i].length
 * isConnected[i][j] is 1 or 0.
 * isConnected[i][i] == 1
 * isConnected[i][j] == isConnected[j][i]
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution { // Independently solved
public:

    int* uf;

    size_t find(size_t i) {
        int& curr(uf[i]);
        if (curr < 0) {
            return i;
        }
        curr = (int)find(curr);
        return curr;
    }

    bool uni(size_t i, size_t j) {
        size_t pi(find(i));
        size_t pj(find(j));
        if (pi == pj) {
            return false;
        }

        int si(uf[pi]);
        int sj(uf[pj]);

        if (si > sj) {
            int temp(pi);
            pi = pj;
            pj = temp;
        }
        uf[pi] += uf[pj];
        uf[pj] = pi;
        
        return true;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        const size_t n(isConnected.size());
        uf = new int[n];
        for (size_t i(0); i < n; ++i) {
            uf[i] = -1;
        }
        int count(n);
        for (size_t i(0); i < n; ++i) {
            for (size_t j(i + 1); j < n; ++j) {
                // cout << i << ':' << find(i) << ' ' << j << ':' << find(j) << '\n';
                if (isConnected.at(i).at(j) && uni(i, j)) {
                    --count;
                }
            }
        }

        delete[] uf;
        return count;
    }
};
// @lc code=end

