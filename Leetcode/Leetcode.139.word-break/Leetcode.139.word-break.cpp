/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break/description/
 *
 * algorithms
 * Medium (45.07%)
 * Likes:    15114
 * Dislikes: 633
 * Total Accepted:    1.4M
 * Total Submissions: 3.1M
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * Given a string s and a dictionary of strings wordDict, return true if s can
 * be segmented into a space-separated sequence of one or more dictionary
 * words.
 * 
 * Note that the same word in the dictionary may be reused multiple times in
 * the segmentation.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "leetcode", wordDict = ["leet","code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet
 * code".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "applepenapple", wordDict = ["apple","pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple
 * pen apple".
 * Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 300
 * 1 <= wordDict.length <= 1000
 * 1 <= wordDict[i].length <= 20
 * s and wordDict[i] consist of only lowercase English letters.
 * All the strings of wordDict are unique.
 * 
 * 
 */

// @lc code=start
class Solution { // Learned from solution, (individually wrote prefix tree)
public:
    
    struct Node {
        Node* nexts[26];
        bool end = false;
        Node() {
            for (size_t i(0); i < 26; ++i) {
                nexts[i] = nullptr;
            }
            end = false;
        }

    };

    Node* root = new Node();
    string s;
    size_t size;
    // size_t level = 0;
    void add(const string& toAdd) {
        Node* curr(root);
        size_t size(toAdd.size());
        for (size_t i(1); i <= size; ++i) {
            size_t idx(toAdd.at(size - i) - 'a');
            Node*& next(curr->nexts[idx]);
            if (next == nullptr) {
                next = new Node();
            }
            curr = next;
        }
        curr->end = true;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        
        for (string& word : wordDict) {
            add(word);
        }

        size_t s_size(s.size());
        vector<bool> dp(s_size + 1, false);
        dp[0] = true;
        for (size_t i(1); i <= s_size; ++i) {
            Node* curr(root);
            for (size_t j(i); j > 0; --j) {
                curr = curr->nexts[s.at(j - 1) - 'a'];
                // cout << s.at(j - 1);
                if (curr == nullptr) {
                    break;
                }
                if (curr -> end && dp[j - 1]) {
                    dp[i] = true;
                    break;
                }
            }
            // cout << '\n';
        }

        return dp[s_size];
    }
};
// @lc code=end

