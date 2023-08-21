/*
 * @lc app=leetcode id=1203 lang=cpp
 *
 * [1203] Sort Items by Groups Respecting Dependencies
 *
 * https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/description/
 *
 * algorithms
 * Hard (49.94%)
 * Likes:    1526
 * Dislikes: 265
 * Total Accepted:    47.4K
 * Total Submissions: 70K
 * Testcase Example:  '8\n2\n[-1,-1,1,0,0,1,0,-1]\n[[],[6],[5],[6],[3,6],[],[],[]]'
 *
 * There are n items each belonging to zero or one of m groups where group[i]
 * is the group that the i-th item belongs to and it's equal to -1 if the i-th
 * item belongs to no group. The items and the groups are zero indexed. A group
 * can have no item belonging to it.
 * 
 * Return a sorted list of the items such that:
 * 
 * 
 * The items that belong to the same group are next to each other in the sorted
 * list.
 * There are some relations between these items where beforeItems[i] is a list
 * containing all the items that should come before the i-th item in the sorted
 * array (to the left of the i-th item).
 * 
 * 
 * Return any solution if there is more than one solution and return an empty
 * list if there is no solution.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems =
 * [[],[6],[5],[6],[3,6],[],[],[]]
 * Output: [6,3,4,1,5,2,0,7]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems =
 * [[],[6],[5],[6],[3],[],[4],[]]
 * Output: []
 * Explanation: This is the same as example 1 except that 4 needs to be before
 * 6 in the sorted list.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= m <= n <= 3 * 10^4
 * group.length == beforeItems.length == n
 * -1 <= group[i] <= m - 1
 * 0 <= beforeItems[i].length <= n - 1
 * 0 <= beforeItems[i][j] <= n - 1
 * i != beforeItems[i][j]
 * beforeItems[i] does not contain duplicates elements.
 * 
 * 
 */

// @lc code=start
class Solution { // Learned from solution
public:
    int n;
    int m;
    vector<int> res_temp, stat;
    vector<list<int>> adj;

    bool topSort(int i) {
        int& curr_stat(stat.at(i));
        if (curr_stat != 0) return curr_stat == 2; // Kind of Dynamic Programming
        curr_stat = 1;
        for (int next : adj.at(i)) {
            if (!topSort(next)) {
                return false;
            }
        }
        curr_stat = 2;
        // cout << i << '\n';
        res_temp.push_back(i);
        return true;
    }

    vector<int> sortItems(int n_, int m_, vector<int>& group, vector<vector<int>>& beforeItems) {
        n = n_;
        m = m_;
        vector<int> res(n);
        stat.resize(n + 2 * m, 0);
        adj.resize(n + 2 * m);
        for (int i(0); i < n; ++i) {
            if (group.at(i) != -1) { // If in a group, link the head and tail of the group to the node
                adj.at(n + group.at(i)).push_back(i);
                adj.at(i).push_back(n + m + group.at(i));
            }
            for (const int j : beforeItems.at(i)) {
                if (group.at(i) != -1 && group.at(i) == group.at(j)) { // Inside the same group
                    adj.at(j).push_back(i);
                } else { // Intergroup relation
                    int ig; // The head of a group
                    if (group.at(i) == -1) {
                        ig = i;
                    } else {
                        ig = n + group.at(i);
                    }
                    int jg; // The head of a group
                    if (group.at(j) == -1) {
                        jg = j;
                    } else {
                        jg = n + m + group.at(j);
                    }
                    adj.at(jg).push_back(ig);
                }
            }
        }
        for (int i(n + 2 * m - 1); i >= 0; --i) {
            if (!topSort(i)) return {};
        }
        const int size(res_temp.size());
        // cout << size;
        int res_i(0);
        for (int i(size - 1); i >= 0; --i) {
            int curr(res_temp.at(i));
            if (curr < n) {
                res.at(res_i) = curr;
                ++res_i;
            }
        }
        return res;
    }
};
// @lc code=end

