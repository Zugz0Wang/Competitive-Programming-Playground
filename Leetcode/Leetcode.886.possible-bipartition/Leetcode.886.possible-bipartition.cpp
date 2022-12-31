/*
 * @lc app=leetcode id=886 lang=cpp
 *
 * [886] Possible Bipartition
 *
 * https://leetcode.com/problems/possible-bipartition/description/
 *
 * algorithms
 * Medium (48.07%)
 * Likes:    2907
 * Dislikes: 65
 * Total Accepted:    130.1K
 * Total Submissions: 267.8K
 * Testcase Example:  '4\n[[1,2],[1,3],[2,4]]'
 *
 * We want to split a group of n people (labeled from 1 to n) into two groups
 * of any size. Each person may dislike some other people, and they should not
 * go into the same group.
 * 
 * Given the integer n and the array dislikes where dislikes[i] = [ai, bi]
 * indicates that the person labeled ai does not like the person labeled bi,
 * return true if it is possible to split everyone into two groups in this
 * way.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
 * Output: true
 * Explanation: group1 [1,4] and group2 [2,3].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 2000
 * 0 <= dislikes.length <= 10^4
 * dislikes[i].length == 2
 * 1 <= dislikes[i][j] <= n
 * ai < bi
 * All the pairs of dislikes are unique.
 * 
 * 
 */
#include <vector>
#include <queue>
#include <map>
using namespace std;
// @lc code=start
class Solution {
public:
    int color[2001];
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        memset(color, 0, sizeof(color));
        map<int, vector<int>> graph;
        for (int i = 1; i <= n; i++) {
            graph.insert(pair<int, vector<int>>(i, {}));
        }
        for (vector<int>& dislike: dislikes) {
            int a = dislike.at(0), b = dislike.at(1);
            graph.at(a).push_back(b);
            graph.at(b).push_back(a);
        }
        for (int i = 1; i <= n; i++) {
            if (color[i] != 0) {
                continue;
            }
            queue<int> wait;
            wait.push(i);
            color[i] = 1;
            while (wait.size() > 0) {
                int curr_idx = wait.front();
                wait.pop();
                int curr_color = color[curr_idx];
                int next_color = 0;
                if (curr_color == 1) {
                    next_color = 2;
                } else {
                    next_color = 1;
                }
                for (int next : graph.at(curr_idx)) {
                    if (color[next] == 0) {
                        wait.push(next);
                        color[next] = next_color;
                    } else if (color[next] != next_color) {
                        return false;
                    }
                }
            }
        }
        
        return true;

    }// 5\n[[1,2],[2,3],[3,4],[4,5],[1,5]]
};
// @lc code=end

