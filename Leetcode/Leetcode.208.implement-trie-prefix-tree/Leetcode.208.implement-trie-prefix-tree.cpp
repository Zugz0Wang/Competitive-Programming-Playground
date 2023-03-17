/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 *
 * https://leetcode.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (59.82%)
 * Likes:    9585
 * Dislikes: 115
 * Total Accepted:    776.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n' +
  '[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * A trie (pronounced as "try") or prefix tree is a tree data structure used to
 * efficiently store and retrieve keys in a dataset of strings. There are
 * various applications of this data structure, such as autocomplete and
 * spellchecker.
 * 
 * Implement the Trie class:
 * 
 * 
 * Trie() Initializes the trie object.
 * void insert(String word) Inserts the string word into the trie.
 * boolean search(String word) Returns true if the string word is in the trie
 * (i.e., was inserted before), and false otherwise.
 * boolean startsWith(String prefix) Returns true if there is a previously
 * inserted string word that has the prefix prefix, and false otherwise.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input
 * ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
 * [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
 * Output
 * [null, null, true, false, true, null, true]
 * 
 * Explanation
 * Trie trie = new Trie();
 * trie.insert("apple");
 * trie.search("apple");   // return True
 * trie.search("app");     // return False
 * trie.startsWith("app"); // return True
 * trie.insert("app");
 * trie.search("app");     // return True
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= word.length, prefix.length <= 2000
 * word and prefix consist only of lowercase English letters.
 * At most 3 * 10^4 calls in total will be made to insert, search, and
 * startsWith.
 * 
 * 
 */
#include <string>
using namespace std;
// @lc code=start
class Trie { // Learned
private:
    struct TreeNode {
        TreeNode* next[26];
        bool end;
        TreeNode() {
            for (int i = 0; i < 26; ++i) {
                next[i] = nullptr;
            }
            end = false;
        }
    };
    TreeNode* root_;

public:
    Trie() {
        root_ = new TreeNode();
    }
    
    void insert(string word) {
        TreeNode* curr = root_;
        for (char c : word) {
            int i = c - 'a';
            TreeNode*& next(curr -> next[i]);
            if (next == nullptr) {
                next = new TreeNode();
            }
            curr = next;
        }
        curr -> end = true;
    }
    
    bool search(string word) {
        TreeNode* curr = root_;
        for (char c : word) {
            int i = c - 'a';
            TreeNode* next(curr -> next[i]);
            if (next == nullptr) {
                return false;
            }
            curr = next;
        }
        return curr->end;
    }
    
    bool startsWith(string prefix) {
        TreeNode* curr = root_;
        for (char c : prefix) {
            int i = c - 'a';
            TreeNode* next(curr -> next[i]);
            if (next == nullptr) {
                return false;
            }
            curr = next;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

