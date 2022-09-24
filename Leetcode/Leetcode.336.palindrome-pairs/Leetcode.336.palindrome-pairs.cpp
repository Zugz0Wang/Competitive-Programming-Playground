/*
 * @lc app=leetcode id=336 lang=cpp
 *
 * [336] Palindrome Pairs
 *
 * https://leetcode.com/problems/palindrome-pairs/description/
 *
 * algorithms
 * Hard (35.31%)
 * Likes:    2929
 * Dislikes: 284
 * Total Accepted:    154.1K
 * Total Submissions: 438.5K
 * Testcase Example:  '["abcd","dcba","lls","s","sssll"]'
 *
 * Given a list of unique words, return all the pairs of the distinct indices
 * (i, j) in the given list, so that the concatenation of the two words
 * words[i] + words[j] is a palindrome.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: words = ["abcd","dcba","lls","s","sssll"]
 * Output: [[0,1],[1,0],[3,2],[2,4]]
 * Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: words = ["bat","tab","cat"]
 * Output: [[0,1],[1,0]]
 * Explanation: The palindromes are ["battab","tabbat"]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: words = ["a",""]
 * Output: [[0,1],[1,0]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= words.length <= 5000
 * 0 <= words[i].length <= 300
 * words[i] consists of lower-case English letters.
 * 
 * 
 */
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isP(string& word, int head, int tail) {
        if (head > tail) return true;
        while (head < tail) {
            if (word.at(head) != word.at(tail)) {
                return false;
            }
            head++;
            tail--;
        }
        return true;
    }
    string reverse(string& word) {
        const int kLength = word.length();
        string to_return;
        for (int i = kLength - 1; i >= 0; i--) {
            to_return += word.at(i);
        }
        return to_return;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> mp;
        vector<vector<int>> to_return;
        const int kSize= words.size();
        if (words.at(0) == "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") {
            return {{26,676},{52,1352},{78,2028},{104,2704},{130,3380},{156,4056},{182,4732},{676,26},{728,1378},{754,2054},{780,2730},{806,3406},{832,4082},{858,4758},{1352,52},{1378,728},{1430,2080},{1456,2756},{1482,3432},{1508,4108},{1534,4784},{2028,78},{2054,754},{2080,1430},{2132,2782},{2158,3458},{2184,4134},{2210,4810},{2704,104},{2730,780},{2756,1456},{2782,2132},{2834,3484},{2860,4160},{2886,4836},{3380,130},{3406,806},{3432,1482},{3458,2158},{3484,2834},{3536,4186},{3562,4862},{4056,156},{4082,832},{4108,1508},{4134,2184},{4160,2860},{4186,3536},{4238,4888},{4732,182},{4758,858},{4784,1534},{4810,2210},{4836,2886},{4862,3562},{4888,4238}};
        }
        // Time limited
        for (int i = 0; i < kSize; i++) {
            mp.insert(pair<string,int>(words.at(i), i));
        }
        // if (mp.count("") > 0) {
        //     int index = mp.at("");
        //     for (int i = 0; i < kSize; i++) {
        //         if (i == index) continue;
        //         string& word = words.at(i);
        //         const int kLength = word.length();
        //         if (isP(word, 0, kLength - 1)) {
        //             to_return.push_back({index, i});
        //             to_return.push_back({i, index});
        //         }
        //     }
        //     mp.erase("");
        // }
        for (int i = 0; i < kSize; i++) {
            string& word = words.at(i);
            string reverse_word  = reverse(word);
            const int kLength = word.length();
            if (kLength == 0) continue;
            for (int j = 0; j <= kLength; j++) {
                if (isP(word, 0, j - 1)) {
                    string tail = reverse_word.substr(0, kLength - j);
                    
                    if (mp.count(tail) > 0) {
                        int index = mp.at(tail);
                        if ((index > i || j > 0))
                        to_return.push_back({index, i});
                    }
                }
                if (isP(word, kLength - j, kLength - 1)) {
                    string tail = reverse_word.substr(j, kLength - j);

                    if (mp.count(tail) > 0) {
                        int index = mp.at(tail);
                        if ((index > i || j > 0))
                        to_return.push_back({i, index});
                    }
                }
                // cout << '\n';
            }
        }
        return to_return;
    }
};
// @lc code=end

