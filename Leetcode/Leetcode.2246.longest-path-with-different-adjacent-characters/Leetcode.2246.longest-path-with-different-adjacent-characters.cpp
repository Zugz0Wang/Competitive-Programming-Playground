/*
 * @lc app=leetcode id=2246 lang=cpp
 *
 * [2246] Longest Path With Different Adjacent Characters
 *
 * https://leetcode.com/problems/longest-path-with-different-adjacent-characters/description/
 *
 * algorithms
 * Hard (44.18%)
 * Likes:    753
 * Dislikes: 20
 * Total Accepted:    18.6K
 * Total Submissions: 39K
 * Testcase Example:  '[-1,0,0,1,1,2]\n"abacbe"'
 *
 * You are given a tree (i.e. a connected, undirected graph that has no cycles)
 * rooted at node 0 consisting of n nodes numbered from 0 to n - 1. The tree is
 * represented by a 0-indexed array parent of size n, where parent[i] is the
 * parent of node i. Since node 0 is the root, parent[0] == -1.
 * 
 * You are also given a string s of length n, where s[i] is the character
 * assigned to node i.
 * 
 * Return the length of the longest path in the tree such that no pair of
 * adjacent nodes on the path have the same character assigned to them.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: parent = [-1,0,0,1,1,2], s = "abacbe"
 * Output: 3
 * Explanation: The longest path where each two adjacent nodes have different
 * characters in the tree is the path: 0 -> 1 -> 3. The length of this path is
 * 3, so 3 is returned.
 * It can be proven that there is no longer path that satisfies the
 * conditions. 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: parent = [-1,0,0,0], s = "aabc"
 * Output: 3
 * Explanation: The longest path where each two adjacent nodes have different
 * characters is the path: 2 -> 0 -> 3. The length of this path is 3, so 3 is
 * returned.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == parent.length == s.length
 * 1 <= n <= 10^5
 * 0 <= parent[i] <= n - 1 for all i >= 1
 * parent[0] == -1
 * parent represents a valid tree.
 * s consists of only lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> graph;
    string s;
    int ans = 0;

    int longest(int curr) {
        int max0 = 0;
        int max1 = 0;
        char curr_char = s.at(curr);
        for (int next : graph.at(curr)) {
            
            int next_max = longest(next);

            if (s.at(next) == curr_char) {
                continue;
            }

            if (next_max > max0) {
                max1 = max0;
                max0 = next_max;
            } else if (next_max > max1) {
                max1 = next_max;
            }
            
        }
        //cout << max0 << ' ' << max1 << '\n';
        if (max0 + max1 + 1 > ans) {
            ans = max0 + max1 + 1;
        }

        return 1 + max0;
    }

    int longestPath(vector<int>& parents, string s0) {
        s = s0;
        const int kSize = parents.size();
        graph.resize(kSize, {});
        for (int i = 1; i < kSize; i++) {
            int parent = parents.at(i);
            graph.at(parent).push_back(i);
        }
        longest(0);
        return ans;
    }
    // [-1,0,1]\n"aab"
};
// @lc code=end

