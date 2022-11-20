/*
 * @lc app=leetcode id=587 lang=cpp
 *
 * [587] Erect the Fence
 *
 * https://leetcode.com/problems/erect-the-fence/description/
 *
 * algorithms
 * Hard (43.17%)
 * Likes:    623
 * Dislikes: 374
 * Total Accepted:    25.4K
 * Total Submissions: 58.8K
 * Testcase Example:  '[[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]'
 *
 * You are given an array trees where trees[i] = [xi, yi] represents the
 * location of a tree in the garden.
 * 
 * You are asked to fence the entire garden using the minimum length of rope as
 * it is expensive. The garden is well fenced only if all the trees are
 * enclosed.
 * 
 * Return the coordinates of trees that are exactly located on the fence
 * perimeter.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: points = [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
 * Output: [[1,1],[2,0],[3,3],[2,4],[4,2]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: points = [[1,2],[2,2],[4,2]]
 * Output: [[4,2],[2,2],[1,2]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= points.length <= 3000
 * points[i].length == 2
 * 0 <= xi, yi <= 100
 * All the given points are unique.
 * 
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) {
        if (a.at(0) == b.at(0)) {
            return a.at(1) < b.at(1);
        }
        return a.at(0) < b.at(0);
    }
    int orientation(vector<int>& a, vector<int>& b, vector<int>& c) {
        return (b.at(0) - a.at(0)) * (c.at(1) - b.at(1)) - (b.at(1) - a.at(1)) * (c.at(0) - b.at(0));
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        const int kSize = trees.size();
        vector<vector<int>> ans;
        sort(trees.begin(), trees.end(), compare);

        for (int i = 0; i < kSize; i++) {
            while (ans.size() > 1 && orientation(ans.at(ans.size() - 2), ans.back(), trees.at(i)) < 0) {
                ans.pop_back();
            } 
            ans.push_back(trees.at(i));
        }

        if (ans.size() == kSize) {
            return ans;
        }

        for (int i = kSize - 2; i >= 0; i--) {
            while (ans.size() > 1 && orientation(ans.at(ans.size() - 2), ans.back(), trees.at(i)) < 0) {
                ans.pop_back();
            } 
            ans.push_back(trees.at(i));
        }
        ans.pop_back();
        return ans;

    }
};
// @lc code=end

