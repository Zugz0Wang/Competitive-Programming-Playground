/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 *
 * https://leetcode.com/problems/word-search-ii/description/
 *
 * algorithms
 * Hard (37.30%)
 * Likes:    6976
 * Dislikes: 302
 * Total Accepted:    490.9K
 * Total Submissions: 1.3M
 * Testcase Example:  '[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n' +
  '["oath","pea","eat","rain"]'
 *
 * Given an m x n board of characters and a list of strings words, return all
 * words on the board.
 * 
 * Each word must be constructed from letters of sequentially adjacent cells,
 * where adjacent cells are horizontally or vertically neighboring. The same
 * letter cell may not be used more than once in a word.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: board =
 * [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]],
 * words = ["oath","pea","eat","rain"]
 * Output: ["eat","oath"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: board = [["a","b"],["c","d"]], words = ["abcb"]
 * Output: []
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == board.length
 * n == board[i].length
 * 1 <= m, n <= 12
 * board[i][j] is a lowercase English letter.
 * 1 <= words.length <= 3 * 10^4
 * 1 <= words[i].length <= 10
 * words[i] consists of lowercase English letters.
 * All the strings of words are unique.
 * 
 * 
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
struct TrieNode {
    TrieNode* children[26] = {};
    string* word;
    void addWord(string& word) {
        TrieNode* cur = this;
        for (char c : word) {
            c -= 'a';
            if (cur->children[c] == nullptr) cur->children[c] = new TrieNode();
            cur = cur->children[c];
        }
        cur->word = &word;
    }
};

class Solution {
public:
    int kRow, kCol;
    int DIR[5] = {0, 1, 0, -1, 0};
    vector<string> ans;
    char b[13][13];
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        kRow = board.size(); kCol = board[0].size();
        TrieNode trieNode;
        for (string& word : words) trieNode.addWord(word);

        for (int row = 0; row < kRow; ++row) {
            for (int col = 0; col < kCol; ++col) {
                b[row][col] = board.at(row).at(col);
            }
        }
            
        for (int r = 0; r < kRow; ++r) {
            for (int c = 0; c < kCol; ++c) {
                dfs(r, c, &trieNode);
            }
        }
                
        return ans;
    }
    void dfs(int r, int c, TrieNode* cur) {
        if (r < 0 || r == kRow || c < 0 || c == kCol || b[r][c] == '#' || cur->children[b[r][c]-'a'] == nullptr) return;
        char orgChar = b[r][c];
        cur = cur->children[orgChar - 'a'];
        if (cur->word != nullptr) {
            ans.push_back(*cur->word);
            cur->word = nullptr; // Avoid duplication!
        }
        b[r][c] = '#'; // mark as visited!
        for (int i = 0; i < 4; ++i) {
            int next_row = r + DIR[i];
            int next_col = c + DIR[i+1];
            if (next_row < 0 || next_row == kRow || next_col < 0 || next_col == kCol || b[next_row][next_col] == '#' || cur->children[b[next_row][next_col]-'a'] == nullptr) continue;
            dfs(r + DIR[i], c + DIR[i+1], cur);
        }
        b[r][c] = orgChar; // restore org state
    }
};
// @lc code=end

