/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 *
 * https://leetcode.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (61.33%)
 * Likes:    9113
 * Dislikes: 296
 * Total Accepted:    558.6K
 * Total Submissions: 887.2K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome. Return all possible palindrome partitioning of s.
 * 
 * 
 * Example 1:
 * Input: s = "aab"
 * Output: [["a","a","b"],["aa","b"]]
 * Example 2:
 * Input: s = "a"
 * Output: [["a"]]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 16
 * s contains only lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string s;
    int kSize;
    vector<string> path;
    vector<vector<string>> ans;
    bool check(int start, int end) {
        if (start >= end) {
            return false;
        }
        end -= 1;
        while (start < end) {
            if (s.at(start) != s.at(end)) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void dfs(int start) {
        if (start >= kSize) {
            ans.push_back(path);
        }
        for (int end = start + 1; end <= kSize; end++) {
            if (check(start, end)) {
                path.push_back(s.substr(start, end - start));
                dfs(end);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s0) {
        s = s0;
        kSize = s0.size();
        dfs(0);
        return ans;
    }
};
// @lc code=end

