/*
 * @lc app=leetcode id=218 lang=cpp
 *
 * [218] The Skyline Problem
 *
 * https://leetcode.com/problems/the-skyline-problem/description/
 *
 * algorithms
 * Hard (39.16%)
 * Likes:    4281
 * Dislikes: 217
 * Total Accepted:    222.5K
 * Total Submissions: 562.1K
 * Testcase Example:  '[[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]'
 *
 * A city's skyline is the outer contour of the silhouette formed by all the
 * buildings in that city when viewed from a distance. Given the locations and
 * heights of all the buildings, return the skyline formed by these buildings
 * collectively.
 * 
 * The geometric information of each building is given in the array buildings
 * where buildings[i] = [lefti, righti, heighti]:
 * 
 * 
 * lefti is the x coordinate of the left edge of the i^th building.
 * righti is the x coordinate of the right edge of the i^th building.
 * heighti is the height of the i^th building.
 * 
 * 
 * You may assume all buildings are perfect rectangles grounded on an
 * absolutely flat surface at height 0.
 * 
 * The skyline should be represented as a list of "key points" sorted by their
 * x-coordinate in the form [[x1,y1],[x2,y2],...]. Each key point is the left
 * endpoint of some horizontal segment in the skyline except the last point in
 * the list, which always has a y-coordinate 0 and is used to mark the
 * skyline's termination where the rightmost building ends. Any ground between
 * the leftmost and rightmost buildings should be part of the skyline's
 * contour.
 * 
 * Note: There must be no consecutive horizontal lines of equal height in the
 * output skyline. For instance, [...,[2 3],[4 5],[7 5],[11 5],[12 7],...] is
 * not acceptable; the three lines of height 5 should be merged into one in the
 * final output as such: [...,[2 3],[4 5],[12 7],...]
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
 * Output: [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
 * Explanation:
 * Figure A shows the buildings of the input.
 * Figure B shows the skyline formed by those buildings. The red points in
 * figure B represent the key points in the output list.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: buildings = [[0,2,3],[2,5,3]]
 * Output: [[0,3],[5,0]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= buildings.length <= 10^4
 * 0 <= lefti < righti <= 2^31 - 1
 * 1 <= heighti <= 2^31 - 1
 * buildings is sorted by lefti in non-decreasing order.
 * 
 * 
 */
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    struct event {
        int L = 0;
        int H = 0;
        int R = 0;
        event(): L(0), H(0), R(0) {}
        event(int l, int h, int r): L(l), H(h), R(r) {};
        bool operator<(event& other) {
            if (L == other.L && H == other.H) {
                return R < other.R;
            }
            if (L == other.L) {
                return H >= other.H;
            }
            return L < other.L;
        }
    };
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        const int kSize = buildings.size();
        vector<event> events(kSize * 2);
        vector<vector<int>> to_return = {};
        int return_size = -1;

        int idx = 0;
        for (vector<int> building : buildings) {
            events.at(idx) = event(building.at(0), building.at(2), building.at(1));
            events.at(idx + 1) = event(building.at(1), 0, 0);
            // cout << idx << '\n';
            idx += 2;
        }
        sort(events.begin(), events.end());

        priority_queue<pair<int, long>> hp;
        hp.push(pair<int, long>(0, 2147483648));

        for (event i : events) {
            if (i.H > 0) {
                hp.push(pair<int, long>(i.H, i.R));
            }

            while (hp.top().second <= i.L) {
                hp.pop();
                // cout<<'1';
            }

            if ((return_size < 0 && hp.top().first != 0) 
                || (return_size >= 0 && to_return.at(return_size).at(1) != hp.top().first)) {
                to_return.push_back({i.L, hp.top().first});
                return_size += 1;
            }
        }
        return to_return;
        
    }
};
// @lc code=end

