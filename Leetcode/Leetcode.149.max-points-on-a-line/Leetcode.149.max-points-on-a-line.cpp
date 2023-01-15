/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 *
 * https://leetcode.com/problems/max-points-on-a-line/description/
 *
 * algorithms
 * Hard (21.24%)
 * Likes:    1760
 * Dislikes: 259
 * Total Accepted:    262.9K
 * Total Submissions: 1.2M
 * Testcase Example:  '[[1,1],[2,2],[3,3]]'
 *
 * Given an array of points where points[i] = [xi, yi] represents a point on
 * the X-Y plane, return the maximum number of points that lie on the same
 * straight line.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: points = [[1,1],[2,2],[3,3]]
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
 * Output: 4
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= points.length <= 300
 * points[i].length == 2
 * -10^4 <= xi, yi <= 10^4
 * All the points are unique.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {

        const int kSize = points.size();
        const double inf = 2147383647;
        int max = 1;
        for (int i = 0; i < kSize; i++) {
            map<double, int> mp;
            int curr_max = -1;
            for (int j = i + 1; j < kSize; j++) {

                int x0 = points.at(i).at(0);
                int y0 = points.at(i).at(1);
                int x1 = points.at(j).at(0);
                int y1 = points.at(j).at(1);
                if (x1 < x0) {
                    swap(x1, x0);
                    swap(y1, y0);
                }
                double k = inf;
                if ((x1 - x0) != 0) {
                    //cout << x1 << ' ' << x0 << ' ' << y1 - y0 << '\n';
                    k = (double) (y1 - y0) / (x1 - x0);
                }
                
                
                if (mp.count(k) > 0) {
                    mp.at(k) += 1;
                } else {
                    mp.insert(pair<double, int>(k, 2));
                }
            }
            
            for (pair<double, int> k : mp) {
                if (k.second > curr_max) {
                    curr_max = k.second;
                }
            }
            mp.clear();
            if (curr_max > max) {
                max = curr_max;
            }
        }
        
        return max;
    }
    // [[0,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
    // [[0,0],[2,2],[-1,-1]]
    // [[0,0],[4,5],[7,8],[8,9],[5,6],[3,4],[1,1]]
};
// @lc code=end

