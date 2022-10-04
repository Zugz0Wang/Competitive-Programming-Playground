/*
 * @lc app=leetcode id=990 lang=cpp
 *
 * [990] Satisfiability of Equality Equations
 *
 * https://leetcode.com/problems/satisfiability-of-equality-equations/description/
 *
 * algorithms
 * Medium (50.56%)
 * Likes:    1943
 * Dislikes: 25
 * Total Accepted:    63K
 * Total Submissions: 124.2K
 * Testcase Example:  '["a==b","b!=a"]'
 *
 * You are given an array of strings equations that represent relationships
 * between variables where each string equations[i] is of length 4 and takes
 * one of two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are
 * lowercase letters (not necessarily different) that represent one-letter
 * variable names.
 * 
 * Return true if it is possible to assign integers to variable names so as to
 * satisfy all the given equations, or false otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: equations = ["a==b","b!=a"]
 * Output: false
 * Explanation: If we assign say, a = 1 and b = 1, then the first equation is
 * satisfied, but not the second.
 * There is no way to assign the variables to satisfy both equations.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: equations = ["b==a","a==b"]
 * Output: true
 * Explanation: We could assign a = 1 and b = 1 to satisfy both equations.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= equations.length <= 500
 * equations[i].length == 4
 * equations[i][0] is a lowercase letter.
 * equations[i][1] is either '=' or '!'.
 * equations[i][2] is '='.
 * equations[i][3] is a lowercase letter.
 * 
 * 
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    char arr[26];
    char find(char c) {
        if (arr[c - 'a'] != c) arr[c - 'a'] = find(arr[c - 'a']);
        return arr[c - 'a'];
    }
    bool equationsPossible(vector<string>& equations) {
        for (int i = 0; i < 26; i++) {
            arr[i] = 'a' + i;
        }
        for (string& equation : equations) {
            char v1 = equation.at(0);
            char v2 = equation.at(3);
            bool equal = equation.at(1) == '=';
            if (equal) {
                arr[find(v1) - 'a'] = find(v2);
            }
        }
        for (string& equation : equations) {
            char v1 = equation.at(0);
            char v2 = equation.at(3);
            bool equal = equation.at(1) == '=';
            if (!equal && find(v1) == find(v2)) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

