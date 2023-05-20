/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 *
 * https://leetcode.com/problems/evaluate-division/description/
 *
 * algorithms
 * Medium (59.14%)
 * Likes:    7389
 * Dislikes: 649
 * Total Accepted:    346.1K
 * Total Submissions: 574.7K
 * Testcase Example:  '[["a","b"],["b","c"]]\n' +
  '[2.0,3.0]\n' +
  '[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]'
 *
 * You are given an array of variable pairs equations and an array of real
 * numbers values, where equations[i] = [Ai, Bi] and values[i] represent the
 * equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a
 * single variable.
 * 
 * You are also given some queries, where queries[j] = [Cj, Dj] represents the
 * j^th query where you must find the answer for Cj / Dj = ?.
 * 
 * Return the answers to all queries. If a single answer cannot be determined,
 * return -1.0.
 * 
 * Note: The input is always valid. You may assume that evaluating the queries
 * will not result in division by zero and that there is no contradiction.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries =
 * [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
 * Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
 * Explanation: 
 * Given: a / b = 2.0, b / c = 3.0
 * queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
 * return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: equations = [["a","b"],["b","c"],["bc","cd"]], values =
 * [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
 * Output: [3.75000,0.40000,5.00000,0.20000]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: equations = [["a","b"]], values = [0.5], queries =
 * [["a","b"],["b","a"],["a","c"],["x","y"]]
 * Output: [0.50000,2.00000,-1.00000,-1.00000]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= equations.length <= 20
 * equations[i].length == 2
 * 1 <= Ai.length, Bi.length <= 5
 * values.length == equations.length
 * 0.0 < values[i] <= 20.0
 * 1 <= queries.length <= 20
 * queries[i].length == 2
 * 1 <= Cj.length, Dj.length <= 5
 * Ai, Bi, Cj, Dj consist of lower case English letters and digits.
 * 
 * 
 */
#include <map>
#include <vector>
using namespace std;
// @lc code=start
class Solution { // Independently solved
public:

    struct Info {
        size_t i;
        double r;

        Info() {
            i = 0;
            r = 1.0;
        }
        void operator=(const Info& other) {
            i = other.i;
            r = other.r;
        }
    };

    Info uf[40];
    map<string, size_t> mp;

    Info find(size_t i) {
        Info& curr(uf[i]);
        
        if (curr.i == i) {
            return curr;
        }
        Info end(find(curr.i));
        curr.i = end.i;
        curr.r = end.r * curr.r;
        return curr;
    }

    bool uni(size_t i, size_t j, double r) {
        Info p_i(find(i));
        Info p_j(find(j));

        size_t idx(p_j.i);

        uf[idx].i = p_i.i;
        uf[idx].r = (p_i.r / p_j.r) * r;

        return true;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        size_t count(0);

        for (size_t i(0); i < 40; ++i) { // Initialize
            Info& curr(uf[i]);
            curr.i = i;
        }

        const size_t size(equations.size());

        for (size_t i(0); i < size; ++i) {
            vector<string>& e(equations.at(i));
            double value(values.at(i));

            size_t i_idx(0);
            size_t j_idx(0);

            const string& i_str(e.at(0));
            const string& j_str(e.at(1));

            if (mp.count(i_str) == 0) {
                mp.insert(pair<string, size_t>(i_str, count));
                i_idx = count;
                ++count;
            } else {
                i_idx = mp.at(i_str);
            }

            if (mp.count(j_str) == 0) {
                mp.insert(pair<string, size_t>(j_str, count));
                j_idx = count;
                ++count;
            } else {
                j_idx = mp.at(j_str);
            }

            uni(i_idx, j_idx, value);
        }
        vector<double> ans;

        for (vector<string>& query : queries) {
            const string& s_i(query.at(0));
            const string& s_j(query.at(1));

            if (mp.count(s_i) == 0 || mp.count(s_j) == 0) { // No such variable
                ans.push_back(-1);
                continue;
            }

            size_t i_idx = mp.at(s_i);
            size_t j_idx = mp.at(s_j);
            Info info_i(find(i_idx));
            Info info_j(find(j_idx));
            if (info_i.i != info_j.i) { // Not in the same group or component, therefore uncomparable
                ans.push_back(-1);
                continue;
            }
            ans.push_back(info_j.r / info_i.r);
        }
        return ans;
    }
};
// @lc code=end

