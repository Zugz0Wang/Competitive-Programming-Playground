/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 *
 * https://leetcode.com/problems/design-add-and-search-words-data-structure/description/
 *
 * algorithms
 * Medium (43.71%)
 * Likes:    5914
 * Dislikes: 341
 * Total Accepted:    473.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '["WordDictionary","addWord","addWord","addWord","search","search","search","search"]\n' +
  '[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]'
 *
 * Design a data structure that supports adding new words and finding if a
 * string matches any previously added string.
 * 
 * Implement the WordDictionary class:
 * 
 * 
 * WordDictionary() Initializes the object.
 * void addWord(word) Adds word to the data structure, it can be matched
 * later.
 * bool search(word) Returns true if there is any string in the data structure
 * that matches word or false otherwise. word may contain dots '.' where dots
 * can be matched with any letter.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input
 * 
 * ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
 * [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
 * Output
 * [null,null,null,null,false,true,true,true]
 * 
 * Explanation
 * WordDictionary wordDictionary = new WordDictionary();
 * wordDictionary.addWord("bad");
 * wordDictionary.addWord("dad");
 * wordDictionary.addWord("mad");
 * wordDictionary.search("pad"); // return False
 * wordDictionary.search("bad"); // return True
 * wordDictionary.search(".ad"); // return True
 * wordDictionary.search("b.."); // return True
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= word.length <= 25
 * word in addWord consists of lowercase English letters.
 * word in search consist of '.' or lowercase English letters.
 * There will be at most 3 dots in word for search queries.
 * At most 10^4 calls will be made to addWord and search.
 * 
 * 
 */
#include <string>
using namespace std;
// @lc code=start
class WordDictionary {
public:
    private:
    struct TreeNode {
        TreeNode* next[26];
        bool end;
        TreeNode() {
            end = false;
            for (int i = 0; i < 26; ++i) {
                next[i] = nullptr;
            }
        }
    };
    TreeNode* root_;

    bool helper(string& word, int idx, TreeNode* subroot) {
        if (subroot == nullptr) {
            return false;
        }
        if (idx >= word.size()) {
            return subroot->end;
        }
        char curr(word.at(idx));
        int next_idx(idx + 1);
        if (curr == '.') {
            for (int i(0); i < 26; ++i) {
                if (helper(word, next_idx, subroot->next[i])) {
                    return true;
                }
            }
            return false;
        } else {
            int curr_idx(curr - 'a');
            return helper(word, next_idx, subroot->next[curr_idx]);
        }
    }

    public:
    WordDictionary() {
        root_ = new TreeNode();
    }
    
    void addWord(string word) {
        TreeNode* curr(root_);
        for (char c : word) {
            int idx(c - 'a');
            if (curr->next[idx] == nullptr) {
                curr->next[idx] = new TreeNode();
            }
            curr = curr->next[idx];
        }
        curr->end = true;
    }
    

    bool search(string word) {
        return helper(word, 0, root_);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

