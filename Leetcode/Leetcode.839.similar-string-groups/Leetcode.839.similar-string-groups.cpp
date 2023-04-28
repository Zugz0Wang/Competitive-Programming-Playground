/*
 * @lc app=leetcode id=839 lang=cpp
 *
 * [839] Similar String Groups
 *
 * https://leetcode.com/problems/similar-string-groups/description/
 *
 * algorithms
 * Hard (46.92%)
 * Likes:    1093
 * Dislikes: 184
 * Total Accepted:    65.6K
 * Total Submissions: 135.8K
 * Testcase Example:  '["tars","rats","arts","star"]'
 *
 * Two strings X and Y are similar if we can swap two letters (in different
 * positions) of X, so that it equals Y. Also two strings X and Y are similar
 * if they are equal.
 * 
 * For example, "tars" and "rats" are similar (swapping at positions 0 and 2),
 * and "rats" and "arts" are similar, but "star" is not similar to "tars",
 * "rats", or "arts".
 * 
 * Together, these form two connected groups by similarity: {"tars", "rats",
 * "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group
 * even though they are not similar.  Formally, each group is such that a word
 * is in the group if and only if it is similar to at least one other word in
 * the group.
 * 
 * We are given a list strs of strings where every string in strs is an anagram
 * of every other string in strs. How many groups are there?
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: strs = ["tars","rats","arts","star"]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: strs = ["omv","ovm"]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= strs.length <= 300
 * 1 <= strs[i].length <= 300
 * strs[i] consists of lowercase letters only.
 * All words in strs have the same length and are anagrams of each other.
 * 
 * 
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution { // Independently solved
public:
    size_t uf[301];
    bool similar(const string& a, const string& b) {
        unsigned count(0);
        const size_t size(a.size());
        for (size_t i(0); i < size; ++i) {
            if (a.at(i) != b.at(i)) {
                ++count;
                if (count > 2) {
                    return false;
                }
            }
        }
        return true;
    }

    size_t find(size_t i) {
        if (uf[i] == i) {
            return i;
        }
        size_t& curr(uf[i]);
        curr = find(curr);
        return curr;
    }

    bool uni(size_t a, size_t b) {
        size_t p_a(find(a));
        size_t p_b(find(b));
        if (p_a == p_b) {
            return false;
        }
        uf[p_b] = p_a;
        return true;
        
    }

    int numSimilarGroups(vector<string>& strs) {
        for (size_t i(0); i < 301; ++i) {
            uf[i] = i;
        }
        const size_t size(strs.size());
        size_t ans(size);
        for (size_t i(0); i < size; ++i) {
            for (size_t j(i + 1); j < size; ++j) {
                if (similar(strs.at(i), strs.at(j))) {
                    if (uni(i, j)) {
                        --ans;
                    }
                    
                }
            }
        }
        return ans;
    }
};
// @lc code=end

