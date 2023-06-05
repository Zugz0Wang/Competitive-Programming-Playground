/*
 * @lc app=leetcode id=1232 lang=cpp
 *
 * [1232] Check If It Is a Straight Line
 *
 * https://leetcode.com/problems/check-if-it-is-a-straight-line/description/
 *
 * algorithms
 * Easy (41.44%)
 * Likes:    1373
 * Dislikes: 188
 * Total Accepted:    154.3K
 * Total Submissions: 383.3K
 * Testcase Example:  '[[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]'
 *
 * You are given an array coordinates, coordinates[i] = [x, y], where [x, y]
 * represents the coordinate of a point. Check if these points make a straight
 * line in the XY plane.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= coordinates.length <= 1000
 * coordinates[i].length == 2
 * -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
 * coordinates contains no duplicate point.
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution { // Independently solved
public:
    struct Dir {
        bool v;
        double r;
        Dir(const vector<int>& a, const vector<int>& b) {

            int dx(b.at(0) - a.at(0));
            int dy(b.at(1) - a.at(1));

            if (dx == 0) {
                v = true;
                r = 0;
            } else {
                v = false;
                r = (double)dy / dx;
                // cout << r << '\n';
            }
        }
        bool operator==(const Dir& other) {
            return (v == other.v && (r == other.r));
        }
    };

    bool checkStraightLine(vector<vector<int>>& cs) {
        Dir dir0(cs.at(0), cs.at(1));
        const size_t size(cs.size());
        for (size_t i(2); i < size; ++i) {
            Dir curr(cs.at(0), cs.at(i));
            if (!(curr == dir0)) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

