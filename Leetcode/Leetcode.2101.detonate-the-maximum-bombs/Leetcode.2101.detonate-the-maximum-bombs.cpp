/*
 * @lc app=leetcode id=2101 lang=cpp
 *
 * [2101] Detonate the Maximum Bombs
 *
 * https://leetcode.com/problems/detonate-the-maximum-bombs/description/
 *
 * algorithms
 * Medium (40.66%)
 * Likes:    1267
 * Dislikes: 84
 * Total Accepted:    36.5K
 * Total Submissions: 83.5K
 * Testcase Example:  '[[2,1,3],[6,1,4]]'
 *
 * You are given a list of bombs. The range of a bomb is defined as the area
 * where its effect can be felt. This area is in the shape of a circle with the
 * center as the location of the bomb.
 * 
 * The bombs are represented by a 0-indexed 2D integer array bombs where
 * bombs[i] = [xi, yi, ri]. xi and yi denote the X-coordinate and Y-coordinate
 * of the location of the i^th bomb, whereas ri denotes the radius of its
 * range.
 * 
 * You may choose to detonate a single bomb. When a bomb is detonated, it will
 * detonate all bombs that lie in its range. These bombs will further detonate
 * the bombs that lie in their ranges.
 * 
 * Given the list of bombs, return the maximum number of bombs that can be
 * detonated if you are allowed to detonate only one bomb.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: bombs = [[2,1,3],[6,1,4]]
 * Output: 2
 * Explanation:
 * The above figure shows the positions and ranges of the 2 bombs.
 * If we detonate the left bomb, the right bomb will not be affected.
 * But if we detonate the right bomb, both bombs will be detonated.
 * So the maximum bombs that can be detonated is max(1, 2) = 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: bombs = [[1,1,5],[10,10,5]]
 * Output: 1
 * Explanation:
 * Detonating either bomb will not detonate the other bomb, so the maximum
 * number of bombs that can be detonated is 1.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: bombs = [[1,2,3],[2,3,1],[3,4,2],[4,5,3],[5,6,4]]
 * Output: 5
 * Explanation:
 * The best bomb to detonate is bomb 0 because:
 * - Bomb 0 detonates bombs 1 and 2. The red circle denotes the range of bomb
 * 0.
 * - Bomb 2 detonates bomb 3. The blue circle denotes the range of bomb 2.
 * - Bomb 3 detonates bomb 4. The green circle denotes the range of bomb 3.
 * Thus all 5 bombs are detonated.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= bombs.length <= 100
 * bombs[i].length == 3
 * 1 <= xi, yi, ri <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:

    vector<vector<size_t>> g;
    vector<bool> visited;
    queue<size_t> wait;
    void addEdge(size_t ia, size_t ib, const vector<int>& a, const vector<int>& b) {
        int dx(a.at(0) - b.at(0));
        int dy(a.at(1) - b.at(1));
        long dis((long)dx * dx + (long)dy * dy);
        long ra(a.at(2));
        long rb(b.at(2));

        if (dis <= ra * ra) {
            g.at(ia).push_back(ib);
        }
        if (dis <= rb * rb) {
            g.at(ib).push_back(ia);
        }
    }

    int bfs(size_t i) {
        for (size_t i(0); i < g.size(); ++i) {
            visited.at(i) = false;
        }
        wait.push(i);
        visited.at(i) = true;
        int size(0);
        while(!wait.empty()) {
            size_t curr_i(wait.front());
            wait.pop();
            ++size;

            const vector<size_t> nexts(g.at(curr_i));
            for (int next : nexts) {
                if (!visited.at(next)) {
                    visited.at(next) = true;
                    wait.push(next);
                }
            }
        }
        return size;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        size_t bombs_size(bombs.size());
        g.resize(bombs_size);
        visited.resize(bombs_size, false);
        for (size_t ia(0); ia < bombs_size; ++ia) {
            for (size_t ib(ia + 1); ib < bombs_size; ++ib) {
                addEdge(ia, ib, bombs.at(ia), bombs.at(ib));
            }
        }
        int ans(1);
        for (size_t i(0); i < bombs_size; ++i) {
            int curr(bfs(i));
            if (curr > ans) {
                ans = curr;
            }
        }
        return ans;
    }
};
// @lc code=end

